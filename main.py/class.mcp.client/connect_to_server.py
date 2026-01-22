import asyncio
from typing import Optional
from contextlib import AsyncExitStack

from mcp import ClientSession, StdioServerParameters
from mcp.client.stdio import stdio_client

from anthropic import Anthropic
from dotenv import load_dotenv

load_dotenv()  # Load environment variables from .env


class MCPClient:
    def __init__(self):
        self.session: Optional[ClientSession] = None
        self.exit_stack = AsyncExitStack()
        self.anthropic = Anthropic()
        self.stdio = None
        self.write = None

    async def connect_to_server(self, server_script_path: str):
        """
        Connect to an MCP server (.py or .js)
        """
        if server_script_path.endswith(".py"):
            command = "python"
        elif server_script_path.endswith(".js"):
            command = "node"
        else:
            raise ValueError("Server script must be .py or .js")

        server_params = StdioServerParameters(
            command=command,
            args=[server_script_path],
            env=None
        )

        # Start stdio transport
        self.stdio, self.write = await self.exit_stack.enter_async_context(
            stdio_client(server_params)
        )

        # Create MCP session
        self.session = await self.exit_stack.enter_async_context(
            ClientSession(self.stdio, self.write)
        )

        await self.session.initialize()

        tools = (await self.session.list_tools()).tools
        print("✅ Connected. Tools:", [tool.name for tool in tools])

    async def process_query(self, query: str) -> str:
        """
        Send query to Claude and let it call MCP tools if needed
        """
        messages = [{"role": "user", "content": query}]

        tool_response = await self.session.list_tools()
        available_tools = [
            {
                "name": tool.name,
                "description": tool.description,
                "input_schema": tool.inputSchema
            }
            for tool in tool_response.tools
        ]

        response = self.anthropic.messages.create(
            model="claude-sonnet-4-20250514",
            max_tokens=1000,
            messages=messages,
            tools=available_tools
        )

        final_output = []

        for item in response.content:
            if item.type == "text":
                final_output.append(item.text)

            elif item.type == "tool_use":
                result = await self.session.call_tool(item.name, item.input)

                messages.append({
                    "role": "assistant",
                    "content": response.content
                })

                messages.append({
                    "role": "user",
                    "content": [{
                        "type": "tool_result",
                        "tool_use_id": item.id,
                        "content": result.content
                    }]
                })

                followup = self.anthropic.messages.create(
                    model="claude-sonnet-4-20250514",
                    max_tokens=1000,
                    messages=messages,
                    tools=available_tools
                )

                final_output.append(followup.content[0].text)

        return "\n".join(final_output)

    async def close(self):
        await self.exit_stack.aclose()

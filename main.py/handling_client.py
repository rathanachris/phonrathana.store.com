async def main():
    client = MCPClient()
    await client.connect_to_server("server.py")
    result = await client.process_query("What tools are available?")
    print(result)
    await client.close()

asyncio.run(main())

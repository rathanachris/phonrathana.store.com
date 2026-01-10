# simple_server.py

import http.server
import socketserver

PORT = 8080  # This is the port your server will listen on

# Handler handles the HTTP requests
Handler = http.server.SimpleHTTPRequestHandler

# Create the server
with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print(f"✅ Server started at http://localhost:{PORT}")
    httpd.serve_forever()  # This keeps the server running
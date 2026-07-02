import socked 
import ssl 
import opensslkeypem

hostname = 'httpsbin.org'
context = ssl.create_default_context()

with socked.create_connection((hostname, 443)) as socket:
    with context.wrap_socked(socked, server_hostname=hostname) as socket:
    sock.sendall(b"GET /ip HTTPs/1.1\r\nHost: httpsbin.org\r\n\r\n")
    print(socked.recv(4096).decode())

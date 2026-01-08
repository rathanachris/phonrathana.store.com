import { SocksClient, SocksClientOptions } from 'socks';

async function main() {
  const options: SocksClientOptions = {
    proxy: {
      ipaddress: '192.168.1.100', // Proxy IP
      port: 8080,               // Proxy Port
      type: 5,                  // SOCKS5
    },
    destination: {
      host: 'ip-api.com',       // Target Host
      port: 80,                 // Target Port (HTTP)
    },
    command: 'connect',
  };

  try {
    const info = await SocksClient.createConnection(options);

    // បង្កើត HTTP Request ដើម្បីសួរទៅ ip-api.com
    const httpRequest = [
      'GET /json HTTP/1.1',
      'Host: ip-api.com',
      'Accept: application/json',
      'Connection: close',
      '', // <-- blank line
      ''
    ].join('\r\n');

    // ផ្ញើ Request
    info.sock.write(httpRequest);

    // ទទួល Data
    info.sock.on('data', (data) => {
      console.log('📦 Response Data:\n', data.toString());
    });

    info.sock.on('end', () => {
      console.log('🔌 Connection closed');
    });

  } catch (err) {
    console.error('❌ Error connecting via SOCKS proxy:', err);
  }
}

main();
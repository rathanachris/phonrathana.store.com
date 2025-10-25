info.socket.on('data', (data) => {
  const text = data.toString();
  const jsonPart = text.substring(text.indexOf('{'));
  try {
    const parsed = JSON.parse(jsonPart);
    console.log('🌍 IP Info:', parsed);
  } catch {
    console.log(text);
  }
});
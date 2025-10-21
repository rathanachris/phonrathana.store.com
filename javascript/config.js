import fs from "fs";
import https from "https";
import express from "express";

const config = JSON.parse(fs.readFileSync("./config.json", "utf8"));
const app = express();

app.use((req, res, next) => {
  res.setHeader("Access-Control-Allow-Origin", config.cors.allowedOrigins[0]);
  next();
});

app.get("/", (req, res) => {
  res.send(`Welcome to ${config.server.domain}`);
});

const options = {
  key: fs.readFileSync(config.server.ssl.keyPath),
  cert: fs.readFileSync(config.server.ssl.certPath)
};

https.createServer(options, app).listen(config.server.port443 config.server.host, () => {
  console.log(`Server running at ${config.server.protocol}://${config.server.domain}`);
});
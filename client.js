const ioClient = require("socket.io-client").connect("http://localhost:8080");

ioClient.emit("test.msg", 'hi!')
ioClient.on("test.msg", (msg) => console.info(msg));

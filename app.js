const server = require("socket.io").listen(8080)

server.on("connection", (socket) => {
    console.log("Novo cliente")
    socket.on("esp.msg", (msg) => {
      console.log("Evento esp.msg:", msg)
      socket.emit("server.msg", "hello ESP8266!")
    })
    socket.on("test.msg", (msg) => {
      console.log("Evento test.msg:", msg)
      socket.emit("test.msg", "this is a test")
    })
})

#include <Arduino.h>
#include <SocketIOClient.h>
#include <WiFiManager.h>


#define HOST "192.168.0.107"
#define PORT 8080
long lastMsg = 0;
void loop();
void setup();

void callback01(String);
void callback02(String);


SocketIOClient socket;
long value=0;

void setup()
{
  Serial.begin(115200);
  WiFiManager wifi;
  wifi.autoConnect();
  socket.on("esp.msg", callback01);
  socket.on("test.msg", callback02);
  if (!socket.connect(HOST, PORT))
  {
    return;
    Serial.println("!socket.connect");
  }
  else if (socket.connected())
  {
    socket.emit("esp.msg", "só teste mesmo");
    Serial.println("connect");
  }
}

void loop()
{
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;

  socket.emit("test.msg", String(++value) );
  }
  socket.monitor();

}


void callback01(String msg){
  Serial.println("teste WS esp");
  Serial.println(msg);
}
void callback02(String msg){
  Serial.println("teste WS teste");
  Serial.println(msg);
}

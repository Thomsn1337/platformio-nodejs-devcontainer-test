#include <Arduino.h>
#include <PsychicHttp.h>
#include <WiFi.h>
#include <env.h>

PsychicHttpServer server;

esp_err_t handleApi(PsychicRequest* request);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, passwd);
  while (WiFi.status() != WL_CONNECTED) {
    ;
  }
  Serial.println(WiFi.localIP());

  server.listen(80);

  server.on("/api", handleApi);
}

void loop() {}

esp_err_t handleApi(PsychicRequest* request) {
  Serial.println("Hello from API");

  return request->reply(200, "text/plain", "Hello World");
}
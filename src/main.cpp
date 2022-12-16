#include <Arduino.h>
#include "canvas.h"
#include "esp_timer.h"
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include "passwords.h"

AsyncWebServer server(80);

c_canvas canvas(OLED_WIDTH, OLED_HEIGHT);
c_snowstorm storm;

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PSSWD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    log_e(".");
  }
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/plain", "Snowstorm access point. See './update' for deployable updates."); });

  AsyncElegantOTA.begin(&server);
  server.begin();

  canvas.init();
  canvas.clear();
  canvas.show();
}

void loop()
{
  canvas.draw(&storm);
  canvas.show();
  delay(150);
  canvas.remove(&storm);
  storm.update();
}
#include <Arduino.h>
#include "canvas.h"
#include "esp_timer.h"

c_canvas canvas(OLED_WIDTH, OLED_HEIGHT);
c_snowstorm storm;

void setup()
{
  Serial.begin(115200);
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
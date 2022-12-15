#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <Arduino.h>
#include <Adafruit_SSD1327.h>
#include "snowstorm.h"

#define OLED_RESET -1
#define OLED
#define OLED_WIDTH 128
#define OLED_HEIGHT 128

class c_canvas
{
public:
    c_canvas(uint8_t w, uint8_t h);
    void init();
    void draw(c_snowflake *pFlake);
    void draw(c_snowstorm *pStorm);
    void remove(c_snowflake *pFlake);
    void remove(c_snowstorm *pStorm);
    void clear();
    void show();
    Adafruit_SSD1327 *pDisplay;

private:
    uint16_t xyToIndex(uint8_t x, uint8_t y, uint8_t w)
    {
        return y * w + x;
    }
};

#endif
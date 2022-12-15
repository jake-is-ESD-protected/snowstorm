#include "canvas.h"

c_canvas::c_canvas(uint8_t w, uint8_t h)
{
    pDisplay = new Adafruit_SSD1327(w, h, &Wire, OLED_RESET, 1000000);
}

void c_canvas::init()
{
    if (!pDisplay->begin(0x3C))
    {
        log_e("Unable to start OLED\n");
        while (1)
            yield();
    }
}

void c_canvas::draw(c_snowflake *pFlake)
{
    pDisplay->drawBitmap(
        pFlake->getPos()->get_x(),
        pFlake->getPos()->get_y(),
        pFlake->getImage(),
        pFlake->getSize(),
        pFlake->getSize(),
        pFlake->getDepth());
}

void c_canvas::draw(c_snowstorm *pStorm)
{
    for (uint8_t i = 0; i < MAX_FLAKES_IN_STORM; i++)
    {
        draw(&(pStorm->flakes[i]));
    }
}

void c_canvas::remove(c_snowflake *pFlake)
{
    pDisplay->drawBitmap(
        pFlake->getPos()->get_x(),
        pFlake->getPos()->get_y(),
        pFlake->getImage(),
        pFlake->getSize(),
        pFlake->getSize(),
        0);
}

void c_canvas::remove(c_snowstorm *pStorm)
{
    for (uint8_t i = 0; i < MAX_FLAKES_IN_STORM; i++)
    {
        remove(&(pStorm->flakes[i]));
    }
}

void c_canvas::clear()
{
    pDisplay->clearDisplay();
    pDisplay->display();
}

void c_canvas::show()
{
    pDisplay->display();
}
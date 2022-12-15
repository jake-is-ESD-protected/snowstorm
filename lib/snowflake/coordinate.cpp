#include <coordinate.h>

c_coordinate::c_coordinate()
{
    x = (uint8_t)random(0, 127);
    y = 0;
}

void c_coordinate::update(uint8_t x_pix, uint8_t y_pix)
{
    x += x_pix;
    y += y_pix;
}

uint8_t c_coordinate::get_x()
{
    return x;
}

uint8_t c_coordinate::get_y()
{
    return y;
}
#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <Arduino.h>

class c_coordinate
{
public:
    c_coordinate();
    void update(uint8_t x_pix, uint8_t y_pix);
    uint8_t get_x();
    uint8_t get_y();

private:
    uint8_t x = 0;
    uint8_t y = 0;
};

#endif
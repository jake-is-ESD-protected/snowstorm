#ifndef _SNOWFLAKE_H_
#define _SNOWFLAKE_H_

#include <Arduino.h>
#include <coordinate.h>
#include "style.h"

#define N_STYLES 2

#define MIN_SPEED 3
#define MAX_SPEED 6

class c_snowflake
{
public:
    c_snowflake();
    void updatePos();
    uint8_t getSize();
    uint8_t *getImage();
    c_coordinate *getPos();
    uint8_t getX_speed();
    uint8_t getY_speed();
    uint8_t getDepth();

private:
    void reInit()
    {
        delete pos;
        pos = new c_coordinate();
        assemble((uint8_t)random(0, N_STYLES));
    }

    void assemble(uint8_t type)
    {
        uint8_t _depth = (uint8_t)random(1, 100);
        uint8_t _y_speed = (uint8_t)random(MIN_SPEED, MAX_SPEED);

        switch (type)
        {
        case 0:
            bmp = Schneeflocke1;
            bmp_side = SNOWFLAKE1_W_H;
            depth = _depth;
            y_speed = _y_speed;
            break;
        case 1:
            bmp = Schneeflocke2;
            bmp_side = SNOWFLAKE2_W_H;
            depth = _depth;
            y_speed = _y_speed;
            break;
        case 2:
            bmp = Schneeflocke3;
            bmp_side = SNOWFLAKE3_W_H;
            depth = _depth;
            y_speed = _y_speed;
            break;
        case 3:
            bmp = Schneeflocke4;
            bmp_side = SNOWFLAKE4_W_H;
            depth = _depth;
            y_speed = _y_speed;
            break;
        case 4:
            bmp = Schneeflocke5;
            bmp_side = SNOWFLAKE5_W_H;
            depth = _depth;
            y_speed = _y_speed;
            break;
        case 5:
            bmp = Schneeflocke6;
            bmp_side = SNOWFLAKE6_W_H;
            depth = _depth;
            y_speed = _y_speed;
            break;
        default:
            log_e("Snowflake type '%d' not supported", type);
            break;
        }
    }

    c_coordinate *pos;
    uint8_t *bmp;
    uint8_t bmp_side = 0;

    uint8_t x_speed = 0;
    uint8_t y_speed = 0;
    uint8_t depth = 0;
};

#endif
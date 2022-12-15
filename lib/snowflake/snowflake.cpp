#include "snowflake.h"

c_snowflake::c_snowflake()
{
    pos = new c_coordinate();
    assemble((uint8_t)random(0, N_STYLES));
}

void c_snowflake::updatePos()
{
    pos->update(x_speed, y_speed);

    if (pos->get_y() >= 128)
    {
        reInit();
    }
}

uint8_t c_snowflake::getSize() { return bmp_side; }

uint8_t *c_snowflake::getImage() { return bmp; }

c_coordinate *c_snowflake::getPos() { return pos; }

uint8_t c_snowflake::getX_speed() { return x_speed; }

uint8_t c_snowflake::getY_speed() { return y_speed; }

uint8_t c_snowflake::getDepth() { return depth; }

#include "snowstorm.h"

c_snowstorm::c_snowstorm()
{
}

void c_snowstorm::update()
{
    for (uint8_t i = 0; i < MAX_FLAKES_IN_STORM; i++)
    {
        flakes[i].updatePos();
    }
}
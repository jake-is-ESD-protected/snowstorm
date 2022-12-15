#ifndef _SNOWSTORM_H_
#define _SNOWSTORM_H_

#include <Arduino.h>
#include "snowflake.h"

#define MAX_FLAKES_IN_STORM 25

class c_snowstorm
{
public:
    c_snowstorm();
    void update();
    c_snowflake flakes[MAX_FLAKES_IN_STORM];

private:
};

#endif
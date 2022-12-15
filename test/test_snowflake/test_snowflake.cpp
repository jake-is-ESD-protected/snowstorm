#include <unity.h>
#include <Arduino.h>
#include <Adafruit_SSD1327.h>
#include "canvas.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_coordinate_init()
{
    c_coordinate *c = new c_coordinate();
    TEST_ASSERT_NOT_NULL(c);

    TEST_ASSERT_UINT8_WITHIN(
        OLED_HEIGHT / 2,
        OLED_HEIGHT / 2,
        c->get_x());

    TEST_ASSERT_EQUAL_UINT8(0, c->get_y());
}

void test_coordinate_update()
{
    c_coordinate *c = new c_coordinate();

    uint8_t x_last = c->get_x();
    uint8_t y_last = c->get_y();

    uint8_t x_offs = 1;
    uint8_t y_offs = 1;
    c->update(x_offs, y_offs);

    TEST_ASSERT_EQUAL_UINT8(x_last + x_offs, c->get_x());
    TEST_ASSERT_EQUAL_UINT8(y_last + y_offs, c->get_y());
}

void test_snowflake_init()
{
    c_snowflake *f = new c_snowflake();
    TEST_ASSERT_NOT_NULL(f);

    TEST_ASSERT_EQUAL_UINT8(0, f->getX_speed());
    TEST_ASSERT_UINT8_WITHIN(2, 2, f->getY_speed());
    TEST_ASSERT_UINT8_WITHIN(64, 64, f->getDepth());

    TEST_ASSERT_NOT_NULL(f->getPos());
}

void test_snowflake_randomness()
{
    c_snowflake *f1 = new c_snowflake();
    c_snowflake *f2 = new c_snowflake();

    if (f1->getDepth() == f2->getDepth() &&
        f1->getSize() == f2->getSize() &&
        f1->getX_speed() == f2->getX_speed() &&
        f1->getY_speed() == f2->getY_speed() &&
        f1->getDepth() == f2->getDepth())
    {
        TEST_FAIL();
    }
    else
    {
        TEST_PASS();
    }
}

void setup()
{
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(test_coordinate_init);
    RUN_TEST(test_coordinate_update);
    RUN_TEST(test_snowflake_init);
    RUN_TEST(test_snowflake_randomness);

    UNITY_END();
}

void loop()
{
}
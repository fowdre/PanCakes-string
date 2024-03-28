#include "unity.h"
#include "Adder.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_basic(void)
{
    TEST_ASSERT_EQUAL(3, adder(1, 2));
    TEST_ASSERT_EQUAL(5, adder(2, 3));
    TEST_ASSERT_EQUAL(7, adder(3, 4));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_basic);
    return UNITY_END();
}

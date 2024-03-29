#include "unity.h"
#include "pkstr_new.h"
#include "pkstr_destroy.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_basic(void)
{
    pkstr str = pkstr_new("Hello, World!");

    TEST_ASSERT_EQUAL_STRING("Hello, World!", str);

    pkstr_destroy(str);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_basic);
    return UNITY_END();
}

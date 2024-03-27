#include "Adder.h"
#include "unity.h"

void setUp(void) {
}

void tearDown() {
}

void test_adder() {
    TEST_ASSERT_EQUAL(3, adder(1, 2));
    TEST_ASSERT_EQUAL(5, adder(2, 3));
    TEST_ASSERT_EQUAL(7, adder(3, 4));
    TEST_ASSERT_EQUAL(9, adder(4, 5));
    // TEST_ASSERT_EQUAL(3, adder(1, 1));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_adder);
    return UNITY_END();
}

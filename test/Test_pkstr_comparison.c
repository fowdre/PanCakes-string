#include <stdlib.h>
#include <stdbool.h>

#include "unity.h"

#include "test_utils.h"

#include "pkstr_new.h"
#include "pkstr_destroy.h"
#include "pkstr_comparison.h"

void test_pkstr_equals_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");
    pkstr str1 = pkstr_new("Niko & pancakes");

    bool res = pkstr_equals(str, str1);

    TEST_ASSERT_TRUE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);

    str = pkstr_new("Niko & pancakes");
    str1 = pkstr_new("Niko & stroby");

    res = pkstr_equals(str, str1);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);
}

void test_pkstr_equals_fn_NULL(void)
{
    bool res = pkstr_equals(NULL, NULL);

    TEST_ASSERT_FALSE(res);

    pkstr str = pkstr_new("Niko & pancakes");
    res = pkstr_equals(str, NULL);

    TEST_ASSERT_FALSE(res);

    res = pkstr_equals(NULL, str);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(&str);
}

void test_pkstr_equals_fn_empty(void)
{
    pkstr str = pkstr_new_empty();
    pkstr str1 = pkstr_new_empty();

    bool res = pkstr_equals(str, str1);

    TEST_ASSERT_TRUE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);

    str = pkstr_new_empty();
    str1 = pkstr_new("Niko & pancakes");

    res = pkstr_equals(str, str1);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);
}

void test_pkstr_equals_fn_length(void)
{
    pkstr str = pkstr_new("Niko & pancakes");
    pkstr str1 = pkstr_new("Niko & pancakes & stroby");

    bool res = pkstr_equals(str, str1);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);
}

void test_pkstr_equals_fn_capacity(void)
{
    pkstr str = pkstr_new("Niko & pancakes");
    pkstr str1 = pkstr_new_with_capacity("Niko & pancakes", 727);

    bool res = pkstr_equals(str, str1);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);
}

void test_pkstr_partial_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");
    pkstr str1 = pkstr_new("Niko & pancakes");

    bool res = pkstr_partial_equals(str, str1);

    TEST_ASSERT_TRUE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);

    str = pkstr_new("Niko & pancakes");
    str1 = pkstr_new("Niko & stroby");

    res = pkstr_partial_equals(str, str1);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);
}

void test_pkstr_partial_fn_NULL(void)
{
    bool res = pkstr_partial_equals(NULL, NULL);

    TEST_ASSERT_FALSE(res);

    pkstr str = pkstr_new("Niko & pancakes");
    res = pkstr_partial_equals(str, NULL);

    TEST_ASSERT_FALSE(res);

    res = pkstr_partial_equals(NULL, str);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(&str);
}

void test_pkstr_partial_fn_empty(void)
{
    pkstr str = pkstr_new_empty();
    pkstr str1 = pkstr_new_empty();

    bool res = pkstr_partial_equals(str, str1);

    TEST_ASSERT_TRUE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);

    str = pkstr_new_empty();
    str1 = pkstr_new("Niko & pancakes");

    res = pkstr_partial_equals(str, str1);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(&str);
    pkstr_destroy(&str1);
}

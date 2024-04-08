#include <stdlib.h>
#include <stdbool.h>

#include "unity.h"

#include "pkstr_new.h"
#include "pkstr_destroy.h"
#include "pkstr_advanced.h"

void test_pkstr_is_empty_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    bool is_empty = pkstr_is_empty(str);

    TEST_ASSERT_EQUAL(false, is_empty);

    pkstr_destroy(str);
}

void test_pkstr_is_empty_fn_NULL(void)
{
    bool is_empty = pkstr_is_empty(NULL);

    TEST_ASSERT_EQUAL(true, is_empty);
}

void test_pkstr_is_empty_fn_empty(void)
{
    pkstr str = pkstr_new("");

    bool is_empty = pkstr_is_empty(str);

    TEST_ASSERT_EQUAL(true, is_empty);

    pkstr_destroy(str);
}

void test_pkstr_split_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr *res = pkstr_split(str, " & ");

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_STRING("Niko", res[0]);
    TEST_ASSERT_EQUAL_STRING("pancakes", res[1]);
    TEST_ASSERT_NULL(res[2]);

    for (size_t i = 0; res[i]; i++)
        pkstr_destroy(res[i]);
    free(res);

    pkstr_destroy(str);
}

void test_pkstr_split_fn_NULL(void)
{
    pkstr *res = pkstr_split(NULL, " & ");
    TEST_ASSERT_NULL(res);

    res = pkstr_split("Niko & pancakes", NULL);
    TEST_ASSERT_NULL(res);

    res = pkstr_split(NULL, NULL);
    TEST_ASSERT_NULL(res);
}

void test_pkstr_split_fn_empty(void)
{
    pkstr str = pkstr_new("");

    pkstr *res = pkstr_split(str, " & ");

    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_NULL(res[0]);

    free(res);

    pkstr_destroy(str);
}

void test_pkstr_range_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr str1 = pkstr_range(str, 7, 15);

    TEST_ASSERT_NOT_NULL(str1);
    TEST_ASSERT_EQUAL_STRING("pancakes", str1);

    pkstr_destroy(str1);
    pkstr_destroy(str);
}

void test_pkstr_range_fn_NULL(void)
{
    pkstr str1 = pkstr_range(NULL, 7, 15);

    TEST_ASSERT_NULL(str1);
}

void test_pkstr_range_fn_empty(void)
{
    pkstr str = pkstr_new("");

    pkstr str1 = pkstr_range(str, 7, 15);

    TEST_ASSERT_NOT_NULL(str1);
    TEST_ASSERT_EQUAL_STRING("", str1);

    pkstr_destroy(str1);
    pkstr_destroy(str);
}

void test_pkstr_range_fn_negative(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr str1 = pkstr_range(str, -9, -6);

    TEST_ASSERT_NOT_NULL(str1);
    TEST_ASSERT_EQUAL_STRING("pan", str1);

    pkstr_destroy(str1);
    pkstr_destroy(str);
}

void test_pkstr_range_fn_start_greater_than_length(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr str1 = pkstr_range(str, 20, 25);

    TEST_ASSERT_NOT_NULL(str1);
    TEST_ASSERT_EQUAL_STRING("", str1);

    pkstr_destroy(str1);
    pkstr_destroy(str);
}

void test_pkstr_range_fn_start_greater_than_end(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr str1 = pkstr_range(str, 15, 10);

    TEST_ASSERT_NOT_NULL(str1);
    TEST_ASSERT_EQUAL_STRING("", str1);

    pkstr_destroy(str1);
    pkstr_destroy(str);
}

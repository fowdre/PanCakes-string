#include <stdlib.h>
#include <stdbool.h>

#include "unity.h"

#include "test_utils.h"

#include "pkstr_new.h"
#include "pkstr_destroy.h"
#include "pkstr_search.h"

void test_pkstr_starts_with_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    bool res = pkstr_starts_with(str, "Niko");

    TEST_ASSERT_TRUE(res);

    pkstr_destroy(str);
}

void test_pkstr_starts_with_fn_NULL(void)
{
    bool res = pkstr_starts_with(NULL, NULL);

    TEST_ASSERT_FALSE(res);

    pkstr str = pkstr_new("Niko & pancakes");
    res = pkstr_starts_with(str, NULL);

    TEST_ASSERT_FALSE(res);

    res = pkstr_starts_with(NULL, str);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_starts_with_fn_empty_literal(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    bool res = pkstr_starts_with(str, "");

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_starts_with_fn_basic_false(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    bool res = pkstr_starts_with(str, "pancakes");

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_ends_with_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    bool res = pkstr_ends_with(str, "pancakes");

    TEST_ASSERT_TRUE(res);

    pkstr_destroy(str);
}

void test_pkstr_ends_with_fn_NULL(void)
{
    bool res = pkstr_ends_with(NULL, NULL);

    TEST_ASSERT_FALSE(res);

    pkstr str = pkstr_new("Niko & pancakes");
    res = pkstr_ends_with(str, NULL);

    TEST_ASSERT_FALSE(res);

    res = pkstr_ends_with(NULL, str);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_ends_with_fn_empty_literal(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    bool res = pkstr_ends_with(str, "");

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_ends_with_fn_basic_false(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    bool res = pkstr_ends_with(str, "Niko");

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_ends_with_fn_suffix_larger_than_str(void)
{
    // This test is needed because pkstr_ends_with() uses the following expression:
    // `return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;`
    // If the suffix is larger than the string then `str + str_len - suffix_len` will be a negative value.
    // And the result would be undefined behavior.
    
    pkstr str = pkstr_new("Niko & pancakes");

    bool res = pkstr_ends_with(str, "Niko & pancakes & Niko & pancakes");

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_contains_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    bool res = pkstr_contains(str, "pancakes");

    TEST_ASSERT_TRUE(res);

    pkstr_destroy(str);
}

void test_pkstr_contains_fn_NULL(void)
{
    bool res = pkstr_contains(NULL, NULL);

    TEST_ASSERT_FALSE(res);

    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");
    res = pkstr_contains(str, NULL);

    TEST_ASSERT_FALSE(res);

    res = pkstr_contains(NULL, str);

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_contains_fn_empty_literal(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    bool res = pkstr_contains(str, "");

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_contains_fn_basic_false(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    bool res = pkstr_contains(str, "stroby");

    TEST_ASSERT_FALSE(res);

    pkstr_destroy(str);
}

void test_pkstr_lsearch_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    size_t res = pkstr_lsearch(str, "& pancakes");

    TEST_ASSERT_EQUAL(5, res);

    pkstr_destroy(str);
}

void test_pkstr_lsearch_fn_NULL(void)
{
    ssize_t res = pkstr_lsearch(NULL, NULL);

    TEST_ASSERT_EQUAL(-1, res);

    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");
    res = pkstr_lsearch(str, NULL);

    TEST_ASSERT_EQUAL(-1, res);

    res = pkstr_lsearch(NULL, str);

    TEST_ASSERT_EQUAL(-1, res);

    pkstr_destroy(str);
}

void test_pkstr_lsearch_fn_empty_literal(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    size_t res = pkstr_lsearch(str, "");

    TEST_ASSERT_EQUAL(-1, res);

    pkstr_destroy(str);
}

void test_pkstr_lsearch_fn_basic_not_found(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    size_t res = pkstr_lsearch(str, "stroby");

    TEST_ASSERT_EQUAL(-1, res);

    pkstr_destroy(str);
}

void test_pkstr_rsearch_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    size_t res = pkstr_rsearch(str, "& pancakes");

    TEST_ASSERT_EQUAL(23, res);

    pkstr_destroy(str);
}

void test_pkstr_rsearch_fn_NULL(void)
{
    ssize_t res = pkstr_rsearch(NULL, NULL);

    TEST_ASSERT_EQUAL(-1, res);

    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");
    res = pkstr_rsearch(str, NULL);

    TEST_ASSERT_EQUAL(-1, res);

    res = pkstr_rsearch(NULL, str);

    TEST_ASSERT_EQUAL(-1, res);

    pkstr_destroy(str);
}

void test_pkstr_rsearch_fn_empty_literal(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    size_t res = pkstr_rsearch(str, "");

    TEST_ASSERT_EQUAL(-1, res);

    pkstr_destroy(str);
}

void test_pkstr_rsearch_fn_basic_not_found(void)
{
    pkstr str = pkstr_new("Niko & pancakes & Niko & pancakes");

    size_t res = pkstr_rsearch(str, "stroby");

    TEST_ASSERT_EQUAL(-1, res);

    pkstr_destroy(str);
}

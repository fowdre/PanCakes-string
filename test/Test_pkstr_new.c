#include "unity.h"

#include "test_utils.h"

#include "pkstr_internals.h"
#include "pkstr_new.h"
#include "pkstr_destroy.h"

void test_pkstr_new_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_destroy(str);
}

void test_pkstr_new_fn_NULL(void)
{
    pkstr str = pkstr_new(NULL);
    TEST_ASSERT_EQUAL_STRING("", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 0, BASE_CAPACITY, "");

    pkstr_destroy(str);
}

void test_pkstr_new_with_capacity_fn_basic(void)
{
    pkstr str = pkstr_new_with_capacity("Niko & pancakes", 727);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 15, 727, "Niko & pancakes");

    pkstr_destroy(str);
}

void test_pkstr_new_with_capacity_fn_NULL(void)
{
    pkstr str = pkstr_new_with_capacity(NULL, 727);
    TEST_ASSERT_EQUAL_STRING("", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 0, BASE_CAPACITY, "");

    pkstr_destroy(str);
}

void test_pkstr_new_with_capacity_fn_capacity_less_than_length(void)
{
    pkstr str = pkstr_new_with_capacity("Niko & pancakes", 5);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 15, 15, "Niko & pancakes");

    pkstr_destroy(str);
}

void test_pkstr_new_with_capacity_fn_capacity_equal_length(void)
{
    pkstr str = pkstr_new_with_capacity("Niko & pancakes", 15);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 15, 15, "Niko & pancakes");

    pkstr_destroy(str);
}

void test_pkstr_new_with_capacity_fn_zero_capacity(void)
{
    pkstr str = pkstr_new_with_capacity("Niko & pancakes", 0);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 15, BASE_CAPACITY, "Niko & pancakes");

    pkstr_destroy(str);
}

void test_pkstr_new_empty_fn_basic(void)
{
    pkstr str = pkstr_new_empty();
    TEST_ASSERT_EQUAL_STRING("", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 0, BASE_CAPACITY, "");

    pkstr_destroy(str);
}

void test_pkstr_new_from_pkstr_fn_basic(void)
{
    pkstr str1 = pkstr_new("Niko & pancakes");
    pkstr str = pkstr_new_from_pkstr(str1);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_destroy(str);
    pkstr_destroy(str1);
}

void test_pkstr_new_from_pkstr_fn_NULL(void)
{
    pkstr str = pkstr_new_from_pkstr(NULL);
    TEST_ASSERT_EQUAL_STRING("", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 0, BASE_CAPACITY, "");

    pkstr_destroy(str);
}

void test_pkstr_repeat_fn_basic(void)
{
    pkstr str = pkstr_repeat("NikoCat", 3);
    TEST_ASSERT_EQUAL_STRING("NikoCatNikoCatNikoCat", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 21, 42, "NikoCatNikoCatNikoCat");

    pkstr_destroy(str);
}

void test_pkstr_repeat_fn_NULL(void)
{
    pkstr str = pkstr_repeat(NULL, 3);
    TEST_ASSERT_EQUAL_STRING("", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 0, BASE_CAPACITY, "");

    pkstr_destroy(str);
}

void test_pkstr_repeat_fn_zero_count(void)
{
    pkstr str = pkstr_repeat("NikoCat", 0);
    TEST_ASSERT_EQUAL_STRING("", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 0, BASE_CAPACITY, "");

    pkstr_destroy(str);
}

void test_pkstr_repeat_fn_zero_str(void)
{
    pkstr str = pkstr_repeat("", 3);
    TEST_ASSERT_EQUAL_STRING("", str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_print_pkstr_header(header);
    utils_assert_pkstr_header(header, 0, BASE_CAPACITY, "");

    pkstr_destroy(str);
}


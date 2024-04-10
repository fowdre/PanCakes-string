#include <stdlib.h>
#include <stdbool.h>

#include "unity.h"

#include "pkstr_new.h"
#include "pkstr_destroy.h"
#include "pkstr_byte.h"

void test_pkstr_push_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr_push(&str, '!');
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes!", str);

    pkstr_destroy(str);
}

void test_pkstr_push_fn_NULL(void)
{
    pkstr_push(NULL, '!');
}

void test_pkstr_push_fn_realloc(void)
{
    pkstr str = pkstr_new("-");

    pkstr_push(&str, '|');
    pkstr_push(&str, '-');
    TEST_ASSERT_EQUAL_STRING("-|-", str);

    pkstr_destroy(str);
}

void test_pkstr_pop_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes!");

    pkstr_pop(str);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    pkstr_destroy(str);
}

void test_pkstr_pop_fn_NULL(void)
{
    pkstr_pop(NULL);
}

void test_pkstr_pop_fn_empty(void)
{
    pkstr str = pkstr_new("");

    pkstr_pop(str);
    TEST_ASSERT_EQUAL_STRING("", str);

    pkstr_destroy(str);
}

void test_pkstr_insert_byte_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr_insert_byte(&str, '!', 4);
    TEST_ASSERT_EQUAL_STRING("Niko! & pancakes", str);

    pkstr_destroy(str);
}

void test_pkstr_insert_byte_fn_NULL(void)
{
    pkstr_insert_byte(NULL, '!', 4);
}

void test_pkstr_insert_byte_fn_front(void)
{
    pkstr str = pkstr_new("iko & pancakes");

    pkstr_insert_byte(&str, 'N', 0);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    pkstr_destroy(str);
}

void test_pkstr_insert_byte_fn_middle(void)
{
    pkstr str = pkstr_new("Niko  pancakes");

    pkstr_insert_byte(&str, '&', 5);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes", str);

    pkstr_destroy(str);
}

void test_pkstr_insert_byte_fn_back(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr_insert_byte(&str, '!', 15);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes!", str);

    pkstr_destroy(str);
}

void test_pkstr_insert_byte_fn_out_of_bounds(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr_insert_byte(&str, '!', 727);
    TEST_ASSERT_EQUAL_STRING("Niko & pancakes!", str);

    pkstr_destroy(str);
}

void test_pkstr_insert_byte_fn_realloc(void)
{
    pkstr str = pkstr_new("-");

    pkstr_insert_byte(&str, '|', 1);
    pkstr_insert_byte(&str, '-', 2);
    TEST_ASSERT_EQUAL_STRING("-|-", str);

    pkstr_destroy(str);
}

void test_pkstr_pkstr_lfind_byte_fn_basic(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(4, pkstr_lfind_byte(str, '!'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_lfind_byte_fn_NULL(void)
{
    TEST_ASSERT_EQUAL(-1, pkstr_lfind_byte(NULL, '!'));
}

void test_pkstr_pkstr_lfind_byte_fn_front(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(0, pkstr_lfind_byte(str, 'N'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_lfind_byte_fn_middle(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(6, pkstr_lfind_byte(str, 'P'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_lfind_byte_fn_back(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(4, pkstr_lfind_byte(str, '!'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_lfind_byte_fn_not_found(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(-1, pkstr_lfind_byte(str, '&'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_rfind_byte_fn_basic(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(14, pkstr_rfind_byte(str, '!'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_rfind_byte_fn_NULL(void)
{
    TEST_ASSERT_EQUAL(-1, pkstr_rfind_byte(NULL, '!'));
}

void test_pkstr_pkstr_rfind_byte_fn_front(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(0, pkstr_rfind_byte(str, 'N'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_rfind_byte_fn_middle(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(6, pkstr_rfind_byte(str, 'P'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_rfind_byte_fn_back(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(14, pkstr_rfind_byte(str, '!'));

    pkstr_destroy(str);
}

void test_pkstr_pkstr_rfind_byte_fn_not_found(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    TEST_ASSERT_EQUAL(-1, pkstr_rfind_byte(str, '&'));

    pkstr_destroy(str);
}

void test_pkstr_remove_byte_fn_basic(void)
{
    pkstr str = pkstr_new("Niko! &Pancakes!");

    pkstr_remove_byte(str, 6);
    TEST_ASSERT_EQUAL_STRING("Niko! Pancakes!", str);

    pkstr_destroy(str);
}

void test_pkstr_remove_byte_fn_NULL(void)
{
    pkstr_remove_byte(NULL, 0);
}

void test_pkstr_remove_byte_fn_out_of_bounds(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!&");

    pkstr_remove_byte(str, 727);
    TEST_ASSERT_EQUAL_STRING("Niko! Pancakes!", str);

    pkstr_destroy(str);
}

void test_pkstr_remove_byte_fn_empty(void)
{
    pkstr str = pkstr_new("");

    pkstr_remove_byte(str, 0);
    TEST_ASSERT_EQUAL_STRING("", str);

    pkstr_destroy(str);
}

void test_pkstr_lremove_byte_fn_basic(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    pkstr_lremove_byte(str, '!');
    TEST_ASSERT_EQUAL_STRING("Niko Pancakes!", str);

    pkstr_destroy(str);
}

void test_pkstr_lremove_byte_fn_NULL(void)
{
    pkstr_lremove_byte(NULL, '!');
}

void test_pkstr_lremove_byte_fn_not_found(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    pkstr_lremove_byte(str, '&');
    TEST_ASSERT_EQUAL_STRING("Niko! Pancakes!", str);

    pkstr_destroy(str);
}

void test_pkstr_rremove_byte_fn_basic(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    pkstr_rremove_byte(str, '!');
    TEST_ASSERT_EQUAL_STRING("Niko! Pancakes", str);

    pkstr_destroy(str);
}

void test_pkstr_rremove_byte_fn_NULL(void)
{
    pkstr_rremove_byte(NULL, '!');
}

void test_pkstr_rremove_byte_fn_not_found(void)
{
    pkstr str = pkstr_new("Niko! Pancakes!");

    pkstr_rremove_byte(str, '&');
    TEST_ASSERT_EQUAL_STRING("Niko! Pancakes!", str);

    pkstr_destroy(str);
}

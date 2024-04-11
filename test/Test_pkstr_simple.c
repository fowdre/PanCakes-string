#include <stdlib.h>
#include <stdbool.h>

#include "unity.h"

#include "test_utils.h"

#include "pkstr_new.h"
#include "pkstr_destroy.h"
#include "pkstr_simple.h"
#include "pkstr_internals.h"

void test_pkstr_len_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");

    size_t len = pkstr_len(str);

    TEST_ASSERT_EQUAL(15, len);

    pkstr_destroy(&str);
}

void test_pkstr_len_fn_NULL(void)
{
    size_t len = pkstr_len(NULL);

    TEST_ASSERT_EQUAL(0, len);
}

void test_pkstr_cat_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_t str1 = pkstr_new(" & stroby");

    pkstr_cat(&str, str1);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 24, 30, "Niko & pancakes & stroby");

    pkstr_destroy(&str1);
    pkstr_destroy(&str);
}

void test_pkstr_cat_fn_NULL(void)
{
    pkstr_cat(NULL, NULL);

    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_cat(&str, NULL);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_cat(NULL, str);

    pkstr_destroy(&str);
}

void test_pkstr_cat_fn_realloc(void)
{
    pkstr_t str = pkstr_new("Niko");
    pkstr_t str1 = pkstr_new(" & pancakes & stroby");

    pkstr_cat(&str, str1);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 24, 48, "Niko & pancakes & stroby");

    pkstr_destroy(&str1);
    pkstr_destroy(&str);
}

void test_pkstr_ncat_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");

    pkstr_ncat(&str, " & stroby & pancakes", 9);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 24, 30, "Niko & pancakes & stroby");

    pkstr_destroy(&str);
}

void test_pkstr_ncat_fn_NULL(void)
{
    pkstr_ncat(NULL, NULL, 0);
    pkstr_ncat(NULL, NULL, 1);

    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_ncat(&str, NULL, 1);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_ncat(NULL, str, 1);

    pkstr_destroy(&str);
}

void test_pkstr_ncat_fn_realloc(void)
{
    pkstr_t str = pkstr_new("Niko");
    pkstr_ncat(&str, " & pancakes & stroby", 11);
    pkstr_ncat(&str, " & pancakes & stroby", 11);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 26, 30, "Niko & pancakes & pancakes");

    pkstr_destroy(&str);
}

void test_pkstr_insert_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_t str1 = pkstr_new(" & stroby");

    pkstr_insert(&str, str1, 4);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 24, 30, "Niko & stroby & pancakes");

    pkstr_destroy(&str1);
    pkstr_destroy(&str);
}

void test_pkstr_insert_fn_NULL(void)
{
    pkstr_insert(NULL, NULL, 0);

    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_insert(&str, NULL, 0);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_insert(NULL, str, 0);

    pkstr_destroy(&str);
}

void test_pkstr_insert_fn_larger_index(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_t str1 = pkstr_new(" & stroby");

    pkstr_insert(&str, str1, 727);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 24, 30, "Niko & pancakes & stroby");

    pkstr_destroy(&str1);
    pkstr_destroy(&str);
}

void test_pkstr_insert_fn_realloc(void)
{
    pkstr_t str = pkstr_new("Niko");
    pkstr_t str1 = pkstr_new(" & pancakes & stroby");

    pkstr_insert(&str, str1, 4);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 24, 48, "Niko & pancakes & stroby");

    pkstr_destroy(&str1);
    pkstr_destroy(&str);
}

void test_pkstr_trim_start_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_t str1 = pkstr_new("Nik");

    pkstr_trim_start(str, str1);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "o & pancakes");

    pkstr_destroy(&str);

    str = pkstr_new("Niko & pancakes");

    pkstr_trim_start(str, str1);

    header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "o & pancakes");

    pkstr_destroy(&str1);
    pkstr_destroy(&str);
}

void test_pkstr_trim_start_fn_NULL(void)
{
    pkstr_trim_start(NULL, NULL);

    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_trim_start(str, NULL);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_trim_start(NULL, str);

    pkstr_destroy(&str);
}

void test_pkstr_trim_start_fn_no_trim(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_t str1 = pkstr_new("xyz");

    pkstr_trim_start(str, str1);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_destroy(&str1);
    pkstr_destroy(&str);

}

void test_pkstr_trim_start_fn_all_trim(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_t str1 = pkstr_new("Niko & pancakes");

    pkstr_trim_start(str, str1);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "");

    pkstr_destroy(&str1);
    pkstr_destroy(&str);
}

void test_pkstr_trim_end_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");

    pkstr_trim_end(str, "kes");

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 12, 30, "Niko & panca");

    pkstr_destroy(&str);

    str = pkstr_new("Niko & pancakes");

    pkstr_trim_end(str, "kse");

    header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 12, 30, "Niko & panca");

    pkstr_destroy(&str);
}

void test_pkstr_trim_end_fn_NULL(void)
{
    pkstr_trim_end(NULL, NULL);

    pkstr_t str = pkstr_new("Niko & pancakes");
    pkstr_trim_end(str, NULL);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_trim_end(NULL, str);

    pkstr_destroy(&str);
}

void test_pkstr_trim_end_fn_all_trim(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");

    pkstr_trim_end(str, "Niko & pancakes");

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 0, 30, "");

    pkstr_destroy(&str);
}

void test_pkstr_remove_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & stroby & pancakes");

    pkstr_remove(str, 5, 14);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 48, "Niko & pancakes");

    pkstr_destroy(&str);
}

void test_pkstr_remove_fn_NULL(void)
{
    pkstr_remove(NULL, 0, 0);

    pkstr_t str = pkstr_new("Niko & pancakes");
    
    pkstr_remove(str, 0, 0);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_remove(NULL, 0, 0);

    pkstr_destroy(&str);
}

void test_pkstr_remove_fn_start_greater_than_length(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");

    pkstr_remove(str, 727, 727);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_destroy(&str);
}

void test_pkstr_remove_fn_end_greater_than_length(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");

    pkstr_remove(str, 0, 727);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 0, 30, "");

    pkstr_destroy(&str);
}

void test_pkstr_remove_fn_start_greater_than_end(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes");

    pkstr_remove(str, 5, 4);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "Niko & pancakes");

    pkstr_destroy(&str);
}

void test_pkstr_to_upper_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & pancakes{");

    pkstr_to_upper(str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 16, 32, "NIKO & PANCAKES{");

    pkstr_destroy(&str);
}

void test_pkstr_to_upper_fn_NULL(void)
{
    pkstr_to_upper(NULL);
}

void test_pkstr_to_lower_fn_basic(void)
{
    pkstr_t str = pkstr_new("Niko & PANCAKES");

    pkstr_to_lower(str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 15, 30, "niko & pancakes");

    pkstr_destroy(&str);
}

void test_pkstr_to_lower_fn_NULL(void)
{
    pkstr_to_lower(NULL);
}

#ifndef TEST_UTILS_H
    #define TEST_UTILS_H

    #include "pkstr_types.h"

    // Utils

    void utils_print_pkstr_header(const struct pkstr_header *header);
    void utils_assert_pkstr_header(const struct pkstr_header *header,
    pkstr_uint_t length, pkstr_uint_t capacity, const char *buffer);


    // Tests

    // Test_pkstr_new.c

    void test_pkstr_new_fn_basic(void);
    void test_pkstr_new_fn_NULL(void);
    void test_pkstr_new_with_capacity_fn_basic(void);
    void test_pkstr_new_with_capacity_fn_NULL(void);
    void test_pkstr_new_with_capacity_fn_capacity_less_than_length(void);
    void test_pkstr_new_with_capacity_fn_capacity_equal_length(void);
    void test_pkstr_new_with_capacity_fn_zero_capacity(void);
    void test_pkstr_new_empty_fn_basic(void);
    void test_pkstr_new_from_pkstr_fn_basic(void);
    void test_pkstr_new_from_pkstr_fn_NULL(void);
    void test_pkstr_repeat_fn_basic(void);
    void test_pkstr_repeat_fn_NULL(void);
    void test_pkstr_repeat_fn_zero_count(void);
    void test_pkstr_repeat_fn_zero_str(void);
    
    // Test_pkstr_destroy.c

    void test_pkstr_destroy_fn_basic(void);
    void test_pkstr_destroy_fn_NULL(void);
    void test_pkstr_pkstr_clear_fn_basic(void);
    void test_pkstr_pkstr_clear_fn_NULL(void);

    // Test_pkstr_comparison.c

    void test_pkstr_equals_fn_basic(void);
    void test_pkstr_equals_fn_NULL(void);
    void test_pkstr_equals_fn_empty(void);
    void test_pkstr_equals_fn_length(void);
    void test_pkstr_equals_fn_capacity(void);
    void test_pkstr_partial_fn_basic(void);
    void test_pkstr_partial_fn_NULL(void);
    void test_pkstr_partial_fn_empty(void);

    // Test_pkstr_search.c

    void test_pkstr_starts_with_fn_basic(void);
    void test_pkstr_starts_with_fn_NULL(void);
    void test_pkstr_starts_with_fn_empty_literal(void);
    void test_pkstr_starts_with_fn_basic_false(void);
    void test_pkstr_ends_with_fn_basic(void);
    void test_pkstr_ends_with_fn_NULL(void);
    void test_pkstr_ends_with_fn_empty_literal(void);
    void test_pkstr_ends_with_fn_basic_false(void);
    void test_pkstr_contains_fn_basic(void);
    void test_pkstr_contains_fn_NULL(void);
    void test_pkstr_contains_fn_empty_literal(void);
    void test_pkstr_contains_fn_basic_false(void);
    void test_pkstr_lsearch_fn_basic(void);
    void test_pkstr_lsearch_fn_NULL(void);
    void test_pkstr_lsearch_fn_empty_literal(void);
    void test_pkstr_lsearch_fn_basic_not_found(void);
    void test_pkstr_rsearch_fn_basic(void);
    void test_pkstr_rsearch_fn_NULL(void);
    void test_pkstr_rsearch_fn_empty_literal(void);
    void test_pkstr_rsearch_fn_basic_not_found(void);
    void test_pkstr_ends_with_fn_suffix_larger_than_str(void);

    // Test_pkstr_simple.c

    void test_pkstr_len_fn_basic(void);
    void test_pkstr_len_fn_NULL(void);
    void test_pkstr_cat_fn_basic(void);
    void test_pkstr_cat_fn_NULL(void);
    void test_pkstr_cat_fn_realloc(void);
    void test_pkstr_ncat_fn_basic(void);
    void test_pkstr_ncat_fn_NULL(void);
    void test_pkstr_ncat_fn_realloc(void);
    void test_pkstr_insert_fn_basic(void);
    void test_pkstr_insert_fn_NULL(void);
    void test_pkstr_insert_fn_larger_index(void);
    void test_pkstr_insert_fn_realloc(void);
    void test_pkstr_trim_start_fn_basic(void);
    void test_pkstr_trim_start_fn_NULL(void);
    void test_pkstr_trim_start_fn_no_trim(void);
    void test_pkstr_trim_start_fn_all_trim(void);
    void test_pkstr_trim_end_fn_basic(void);
    void test_pkstr_trim_end_fn_NULL(void);
    void test_pkstr_trim_end_fn_all_trim(void);
    void test_pkstr_remove_fn_basic(void);
    void test_pkstr_remove_fn_NULL(void);
    void test_pkstr_remove_fn_start_greater_than_length(void);
    void test_pkstr_remove_fn_end_greater_than_length(void);
    void test_pkstr_remove_fn_start_greater_than_end(void);
    void test_pkstr_to_upper_fn_basic(void);
    void test_pkstr_to_upper_fn_NULL(void);
    void test_pkstr_to_lower_fn_basic(void);
    void test_pkstr_to_lower_fn_NULL(void);

#endif /* TEST_UTILS_H */

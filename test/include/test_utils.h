#ifndef TEST_UTILS_H
    #define TEST_UTILS_H

    #include "pkstr_types.h"

    // Utils

    void utils_print_pkstr_header(const struct pkstr_header *header);
    void utils_assert_pkstr_header(const struct pkstr_header *header,
    pkstr_uint_t length, pkstr_uint_t capacity, const char *buffer);


    // Tests

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
    void test_pkstr_destroy_fn_basic(void);
    void test_pkstr_destroy_fn_NULL(void);

#endif /* TEST_UTILS_H */

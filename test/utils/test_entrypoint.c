#include "unity.h"

#include "test_utils.h"

int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_pkstr_new_fn_basic);
    RUN_TEST(test_pkstr_new_fn_NULL);

    RUN_TEST(test_pkstr_new_with_capacity_fn_basic);
    RUN_TEST(test_pkstr_new_with_capacity_fn_NULL);
    RUN_TEST(test_pkstr_new_with_capacity_fn_capacity_less_than_length);
    RUN_TEST(test_pkstr_new_with_capacity_fn_capacity_equal_length);
    RUN_TEST(test_pkstr_new_with_capacity_fn_zero_capacity);
    
    RUN_TEST(test_pkstr_new_empty_fn_basic);
    
    RUN_TEST(test_pkstr_new_from_pkstr_fn_basic);
    RUN_TEST(test_pkstr_new_from_pkstr_fn_NULL);

    RUN_TEST(test_pkstr_repeat_fn_basic);
    RUN_TEST(test_pkstr_repeat_fn_NULL);
    RUN_TEST(test_pkstr_repeat_fn_zero_count);
    RUN_TEST(test_pkstr_repeat_fn_zero_str);

    RUN_TEST(test_pkstr_destroy_fn_basic);
    RUN_TEST(test_pkstr_destroy_fn_NULL);
    RUN_TEST(test_pkstr_pkstr_clear_fn_basic);
    RUN_TEST(test_pkstr_pkstr_clear_fn_NULL);

    RUN_TEST(test_pkstr_equals_fn_basic);
    RUN_TEST(test_pkstr_equals_fn_NULL);
    RUN_TEST(test_pkstr_equals_fn_empty);
    RUN_TEST(test_pkstr_equals_fn_length);
    RUN_TEST(test_pkstr_equals_fn_capacity);
    RUN_TEST(test_pkstr_partial_fn_basic);
    RUN_TEST(test_pkstr_partial_fn_NULL);
    RUN_TEST(test_pkstr_partial_fn_empty);

    RUN_TEST(test_pkstr_starts_with_fn_basic);
    RUN_TEST(test_pkstr_starts_with_fn_NULL);
    RUN_TEST(test_pkstr_starts_with_fn_empty_literal);
    RUN_TEST(test_pkstr_starts_with_fn_basic_false);
    RUN_TEST(test_pkstr_ends_with_fn_basic);
    RUN_TEST(test_pkstr_ends_with_fn_NULL);
    RUN_TEST(test_pkstr_ends_with_fn_empty_literal);
    RUN_TEST(test_pkstr_ends_with_fn_basic_false);
    RUN_TEST(test_pkstr_contains_fn_basic);
    RUN_TEST(test_pkstr_contains_fn_NULL);
    RUN_TEST(test_pkstr_contains_fn_empty_literal);
    RUN_TEST(test_pkstr_contains_fn_basic_false);
    RUN_TEST(test_pkstr_lsearch_fn_basic);
    RUN_TEST(test_pkstr_lsearch_fn_NULL);
    RUN_TEST(test_pkstr_lsearch_fn_empty_literal);
    RUN_TEST(test_pkstr_lsearch_fn_basic_not_found);
    RUN_TEST(test_pkstr_rsearch_fn_basic);
    RUN_TEST(test_pkstr_rsearch_fn_NULL);
    RUN_TEST(test_pkstr_rsearch_fn_empty_literal);
    RUN_TEST(test_pkstr_rsearch_fn_basic_not_found);
    RUN_TEST(test_pkstr_ends_with_fn_suffix_larger_than_str);
    
    return UNITY_END();
}

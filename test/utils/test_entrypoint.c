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
    
    return UNITY_END();
}

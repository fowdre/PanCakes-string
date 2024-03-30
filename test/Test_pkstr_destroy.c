#include <stdlib.h>

#include "test_utils.h"
#include "pkstr_new.h"
#include "pkstr_destroy.h"

void test_pkstr_destroy_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");

    pkstr_destroy(str);
}

void test_pkstr_destroy_fn_NULL(void)
{
    pkstr_destroy(NULL);
}

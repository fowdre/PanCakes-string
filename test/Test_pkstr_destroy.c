#include <stdlib.h>

#include "test_utils.h"

#include "pkstr_internals.h"
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

void test_pkstr_pkstr_clear_fn_basic(void)
{
    pkstr str = pkstr_new("Niko & pancakes");
    pkstr_clear(str);

    const struct pkstr_header *header = PKSTR_H_PTR(str);
    utils_assert_pkstr_header(header, 0, 30, "");

    pkstr_destroy(str);
}

void test_pkstr_pkstr_clear_fn_NULL(void)
{
    pkstr_clear(NULL);
}

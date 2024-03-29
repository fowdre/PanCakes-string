#include "unity.h"
#include "pkstr_internals.h"

void setUp(void)
{
    return;
}

void tearDown(void)
{
    return;
}

void utils_assert_pkstr_header(const struct pkstr_header *header,
    pkstr_uint_t length, pkstr_uint_t capacity, const char *buffer)
{
    TEST_ASSERT_NOT_NULL(header);
    
#if PKSTR_HEADER_TYPE == PKSTR_HEADER_TYPE_TINY
    TEST_ASSERT_EQUAL_UINT16(length, header->length);
    TEST_ASSERT_EQUAL_UINT16(capacity, header->capacity);
#elif PKSTR_HEADER_TYPE == PKSTR_HEADER_TYPE_SMALL
    TEST_ASSERT_EQUAL_UINT32(length, header->length);
    TEST_ASSERT_EQUAL_UINT32(capacity, header->capacity);
#elif PKSTR_HEADER_TYPE == PKSTR_HEADER_TYPE_MEDIUM
    TEST_ASSERT_EQUAL_UINT32(length, header->length);
    TEST_ASSERT_EQUAL_UINT32(capacity, header->capacity);
#elif PKSTR_HEADER_TYPE == PKSTR_HEADER_TYPE_LARGE
    TEST_ASSERT_EQUAL_UINT64(length, header->length);
    TEST_ASSERT_EQUAL_UINT64(capacity, header->capacity);
#endif
    TEST_ASSERT_EQUAL_STRING(buffer, header->buffer);
}

#include <inttypes.h>

void utils_print_pkstr_header(const struct pkstr_header *header)
{
    printf("Capacity\t->\t%"PRIu64"\n", header->capacity);
    printf("Length\t->\t%"PRIu64"\n", header->length);
    printf("Buffer\t->\t[%s]\n", header->buffer);
}

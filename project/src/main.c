#include <stdio.h>

#include "pkstr_internals.h"
#include "pkstr_new.h"
#include "pkstr_destroy.h"
#include "pkstr_types.h"

int main(void)
{
    pkstr str = pkstr_new("Hello, World!");

#if 1

    struct pkstr_header *header = PKSTR_H_PTR(str);
    
    printf("Length -> %d\n", header->length);
    printf("Capacity -> %d\n", header->capacity);
    printf("Buffer -> [%s]\n", header->buffer);

#endif

    pkstr_destroy(str);
}

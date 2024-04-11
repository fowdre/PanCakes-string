/*
    pan<C>akes<🥞> string is an implementation of a heap-allocated string.
    It is part of the pan<C>akes<🥞> collection, aimed to provide tools to
    help with C programming.
    pan<C>akes<🥞> string  Copyright (C) 2024  Fowdre

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pkstr_internals.h"


char *pkstr_new_empty(void)
{
    return i_pkstr_new_from_raw_parts(0, BASE_CAPACITY, NULL);
}

char *pkstr_new(const char *str)
{
    pkstr_uint_t len = 0;
    pkstr_uint_t capacity = 0;
    char *new_str;

    if (str == NULL)
        return pkstr_new_empty();
    len = (pkstr_uint_t)strlen(str);
    capacity = i_pkstr_recompute_capacity(len);
    new_str = i_pkstr_new_from_raw_parts(len, capacity, str);
    if (new_str == NULL)
        return NULL;
    return new_str;
}

char *pkstr_new_with_capacity(const char *str, pkstr_uint_t capacity)
{
    pkstr_uint_t len = 0;
    char *new_str;

    if (str == NULL)
        return pkstr_new_empty();
    len = (pkstr_uint_t)strlen(str);
    if (capacity == 0)
        capacity = BASE_CAPACITY;
    else if (capacity < len)
        capacity = len;
    new_str = i_pkstr_new_from_raw_parts(len, capacity, str);
    if (new_str == NULL)
        return NULL;
    return new_str;
}

pkstr_t pkstr_new_from_pkstr(const pkstr_t str)
{
    const struct pkstr_header *header = PKSTR_H_PTR(str);

    if (str == NULL)
        return pkstr_new_empty();
    return i_pkstr_new_from_raw_parts(
        header->length, header->capacity, header->buffer);
}

pkstr_t pkstr_repeat(const char *str, pkstr_uint_t count)
{
    pkstr_uint_t len = 0;
    pkstr_uint_t capacity = 0;
    char *new_str;

    if (str != NULL)
        len = (pkstr_uint_t)strlen(str);
    capacity = i_pkstr_recompute_capacity(len * count);
    if (str == NULL)
        return pkstr_new_empty();
    new_str = i_pkstr_new_from_raw_parts(len * count, capacity, NULL);
    if (new_str == NULL)
        return NULL;
    for (pkstr_uint_t i = 0; i < count; i++)
        strcat(new_str, str);
    return new_str;
}

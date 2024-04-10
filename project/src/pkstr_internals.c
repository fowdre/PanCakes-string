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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pkstr_internals.h"

pkstr_uint_t i_pkstr_recompute_capacity(pkstr_uint_t value)
{
    if (value <= 0)
        return BASE_CAPACITY;
    if (value > (MAX_CAPACITY / CAPACITY_INCREASE_FACTOR))
        return MAX_CAPACITY;
    return value * CAPACITY_INCREASE_FACTOR;
}

struct pkstr_header *i_pkstr_header_new(
    pkstr_uint_t len, pkstr_uint_t capacity, const char *str)
{
    size_t alloc_size = PKSTR_H_SIZE + (sizeof(char) * (capacity + len + 1));
    struct pkstr_header *new_header;

    new_header = malloc(alloc_size);
    if (new_header == NULL)
        return NULL;
    memset(new_header, 0, alloc_size);
    new_header->capacity = capacity;
    new_header->length = len;
    if (str != NULL)
        memcpy(new_header->buffer, str, len);
    return new_header;
}

char *i_pkstr_new_from_raw_parts(
    pkstr_uint_t len, pkstr_uint_t capacity, const char *str)
{
    struct pkstr_header *new_header;

    new_header = i_pkstr_header_new(len, capacity, str);
    if (new_header == NULL)
        return NULL;
    return new_header->buffer;
}

pkstr i_pkstr_get_new_extend(pkstr str, pkstr_uint_t new_capacity)
{
    struct pkstr_header *header;
    struct pkstr_header *new_header;

    if (str == NULL)
        return str;
    header = PKSTR_H_PTR(str);
    if (new_capacity <= header->capacity)
        return str;
    new_header = i_pkstr_header_new(
        header->length, new_capacity, header->buffer);
    if (new_header == NULL)
        return str;
    free(header);
    return new_header->buffer;
}

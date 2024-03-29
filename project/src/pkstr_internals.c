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
#include "pkstr_types.h"

pkstr_uint_t i_pkstr_recompute_capacity(pkstr_uint_t value)
{
    if (value <= 0)
        return BASE_CAPACITY;
    if (value > (MAX_CAPACITY / CAPACITY_INCREASE_FACTOR))
        return MAX_CAPACITY;
    return value * CAPACITY_INCREASE_FACTOR;
}

char *i_pkstr_new_from_raw_parts(
    pkstr_uint_t len, pkstr_uint_t capacity, const char *str)
{
    size_t alloc_size = PKSTR_H_SIZE + (sizeof(char) * (capacity + len + 1));
    struct pkstr_header *new_str;

    new_str = malloc(alloc_size);
    if (new_str == NULL)
        return NULL;
    memset(new_str, 0, alloc_size);
    new_str->capacity = capacity;
    new_str->length = len;
    if (str != NULL)
        memcpy(new_str->buffer, str, len);
    return new_str->buffer;
}

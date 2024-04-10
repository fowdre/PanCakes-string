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
#include <stdlib.h>
#include <string.h>

#include "pkstr_internals.h"

pkstr_uint_t pkstr_len(const pkstr str)
{
    if (str == NULL)
        return 0;
    return PKSTR_H_PTR(str)->length;
}

void pkstr_cat(pkstr *str1, const pkstr str2)
{
    pkstr_uint_t new_length = 0;
    struct pkstr_header *header1;
    const struct pkstr_header *header2;

    if (str1 == NULL || str2 == NULL)
        return;
    header1 = PKSTR_H_PTR(*str1);
    header2 = PKSTR_H_PTR(str2);
    new_length = header1->length + header2->length;
    if (new_length > header1->capacity)
        *str1 = i_pkstr_get_new_extend(
                    *str1, i_pkstr_recompute_capacity(new_length));
    if (*str1 == NULL)
        return;
    strncat(*str1, str2, header2->length);
    header1 = PKSTR_H_PTR(*str1);
    header1->length = new_length;
}

void pkstr_ncat(pkstr *str1, const pkstr str2, pkstr_uint_t n)
{
    pkstr_uint_t new_length = 0;
    struct pkstr_header *header1;

    if (n == 0)
        return;
    if (str1 == NULL || str2 == NULL)
        return;
    header1 = PKSTR_H_PTR(*str1);
    new_length = header1->length + n;
    if (new_length > header1->capacity)
        *str1 = i_pkstr_get_new_extend(
                    *str1, i_pkstr_recompute_capacity(new_length));
    if (*str1 == NULL)
        return;
    strncat(*str1, str2, n);
    header1 = PKSTR_H_PTR(*str1);
    header1->length = new_length;
}

void pkstr_insert(pkstr *str1, const pkstr str2, pkstr_uint_t index)
{
    pkstr_uint_t new_length = 0;
    struct pkstr_header *h1;
    const struct pkstr_header *h2;

    if (str1 == NULL || str2 == NULL)
        return;
    h1 = PKSTR_H_PTR(*str1);
    h2 = PKSTR_H_PTR(str2);
    if (index > h1->length)
        index = h1->length;
    new_length = h1->length + h2->length;
    if (new_length > h1->capacity)
        *str1 = i_pkstr_get_new_extend(
                    *str1, i_pkstr_recompute_capacity(new_length));
    if (*str1 == NULL)
        return;
    h1 = PKSTR_H_PTR(*str1);
    h1->length = new_length;
    memmove(*str1 + index + h2->length, *str1 + index, h1->length - index);
    memcpy(*str1 + index, str2, h2->length);
}

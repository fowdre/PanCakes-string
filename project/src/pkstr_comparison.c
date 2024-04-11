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
#include <string.h>

#include "pkstr_internals.h"

bool pkstr_partial_equals(const pkstr_t str1, const pkstr_t str2)
{
    if (str1 == NULL || str2 == NULL)
        return false;
    return strcmp(str1, str2) == 0;
}

bool pkstr_equals(const pkstr_t str1, const pkstr_t str2)
{
    const struct pkstr_header *header1;
    const struct pkstr_header *header2;

    if (str1 == NULL || str2 == NULL)
        return false;
    header1 = PKSTR_H_PTR(str1);
    header2 = PKSTR_H_PTR(str2);
    if (header1->length != header2->length)
        return false;
    if (header1->capacity != header2->capacity)
        return false;
    return pkstr_partial_equals(str1, str2);
}

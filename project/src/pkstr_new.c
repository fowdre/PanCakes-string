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

char *pkstr_new(const char *str)
{
    pkstr_uint_t len = 0;
    pkstr_uint_t capacity = 0;
    char *new_str;

    if (str != NULL)
        len = (pkstr_uint_t)strlen(str);
    capacity = i_pkstr_recompute_capacity(len);
    new_str = i_pkstr_new_from_raw_parts(len, capacity, str);
    if (new_str == NULL)
        return NULL;
    return new_str;
}

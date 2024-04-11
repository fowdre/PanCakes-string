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

bool pkstr_starts_with(const pkstr_t str, const char *prefix)
{
    size_t prefix_len;

    if (str == NULL || prefix == NULL)
        return false;
    prefix_len = strlen(prefix);
    if (prefix_len == 0)
        return false;
    return strncmp(str, prefix, prefix_len) == 0;
}

bool pkstr_ends_with(const pkstr_t str, const char *suffix)
{
    pkstr_uint_t str_len;
    size_t suffix_len;

    if (str == NULL || suffix == NULL)
        return false;
    str_len = PKSTR_H_PTR(str)->length;
    suffix_len = strlen(suffix);
    if (suffix_len == 0)
        return false;
    if (str_len < suffix_len)
        return false;
    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;
}

bool pkstr_contains(const pkstr_t str, const char *substr)
{
    size_t substr_len;

    if (str == NULL || substr == NULL)
        return false;
    substr_len = strlen(substr);
    if (substr_len == 0)
        return false;
    return strstr(str, substr) != NULL;
}

ssize_t pkstr_lsearch(const pkstr_t str, const char *substr)
{
    const char *result;
    size_t substr_len;

    if (str == NULL || substr == NULL)
        return -1;
    substr_len = strlen(substr);
    if (substr_len == 0)
        return -1;
    result = strstr(str, substr);
    if (result == NULL)
        return -1;
    return result - str;
}

ssize_t pkstr_rsearch(const pkstr_t str, const char *substr)
{
    const char *strstr_res;
    const char *str_ptr = str;
    const char *result = NULL;

    if (str == NULL || substr == NULL)
        return -1;
    if (strlen(substr) == 0)
        return -1;
    while (true) {
        strstr_res = strstr(str_ptr, substr);
        if (strstr_res == NULL)
            break;
        result = strstr_res;
        str_ptr = strstr_res + 1;
    }
    if (result == NULL)
        return -1;
    return result - str;
}

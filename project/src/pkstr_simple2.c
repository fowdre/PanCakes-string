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

static bool pkstr_trim_i_byte_in_bytes(char byte, const char *bytes)
{
    for (size_t i = 0; bytes[i] != '\0'; i++)
        if (byte == bytes[i])
            return true;
    return false;
}

void pkstr_trim_start(const pkstr str, const char *bytes)
{
    const struct pkstr_header *header;
    pkstr_uint_t bytes_to_trim = 0;

    if (str == NULL || bytes == NULL)
        return;
    header = PKSTR_H_PTR(str);
    for (pkstr_uint_t i = 0; i < header->length; i++) {
        if (pkstr_trim_i_byte_in_bytes(str[i], bytes))
            bytes_to_trim++;
        else
            break;
    }
    if (bytes_to_trim == 0)
        return;
    memmove(str, str + bytes_to_trim, header->length - bytes_to_trim);
    memset(str + header->length - bytes_to_trim, 0, bytes_to_trim);
}

void pkstr_trim_end(const pkstr str, const char *bytes)
{
    struct pkstr_header *header;
    pkstr_uint_t bytes_to_trim = 0;

    if (str == NULL || bytes == NULL)
        return;
    header = PKSTR_H_PTR(str);
    for (pkstr_uint_t i = header->length; i > 0; i--) {
        if (pkstr_trim_i_byte_in_bytes(str[i - 1], bytes))
            bytes_to_trim++;
        else
            break;
    }
    header->length -= bytes_to_trim;
    memset(str + header->length, 0, bytes_to_trim);
}

void pkstr_remove(
    const pkstr str, pkstr_uint_t index_start, pkstr_uint_t index_end)
{
    struct pkstr_header *header;
    pkstr_uint_t new_length = 0;

    if (str == NULL)
        return;
    header = PKSTR_H_PTR(str);
    if (index_start >= header->length)
        return;
    if (index_end >= header->length)
        index_end = header->length;
    if (index_start > index_end)
        return;
    new_length = header->length - (index_end - index_start);
    memmove(str + index_start, str + index_end, new_length);
    header->length = new_length;
    memset(str + header->length, 0, index_end - index_start);
}

void pkstr_to_upper(const pkstr str)
{
    if (str == NULL)
        return;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}

void pkstr_to_lower(const pkstr str)
{
    if (str == NULL)
        return;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
}

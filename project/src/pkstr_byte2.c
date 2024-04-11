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

#include <stdlib.h>

#include "pkstr_internals.h"

int pkstr_lfind_byte(const pkstr_t str, char byte)
{
    const struct pkstr_header *header;

    if (str == NULL)
        return -1;
    header = PKSTR_H_PTR(str);
    for (pkstr_uint_t i = 0; i < header->length; i++)
        if (str[i] == byte)
            return i;
    return -1;
}

int pkstr_rfind_byte(const pkstr_t str, char byte)
{
    const struct pkstr_header *header;

    if (str == NULL)
        return -1;
    header = PKSTR_H_PTR(str);
    for (pkstr_uint_t i = header->length; i > 0; i--) {
        if (str[i - 1] == byte)
            return i - 1;
    }
    return -1;
}

void pkstr_remove_byte(const pkstr_t str, pkstr_uint_t index)
{
    struct pkstr_header *header;

    if (str == NULL)
        return;
    header = PKSTR_H_PTR(str);
    if (header->length == 0)
        return;
    if (index > header->length)
        index = header->length;
    for (pkstr_uint_t i = index; i < header->length - 1; i++)
        str[i] = str[i + 1];
    header->buffer[header->length - 1] = '\0';
    header->length--;
}

void pkstr_lremove_byte(const pkstr_t str, char byte)
{
    const struct pkstr_header *header;

    if (str == NULL)
        return;
    header = PKSTR_H_PTR(str);
    for (pkstr_uint_t i = 0; i < header->length; i++) {
        if (str[i] == byte) {
            pkstr_remove_byte(str, i);
            return;
        }
    }
}

void pkstr_rremove_byte(const pkstr_t str, char byte)
{
    const struct pkstr_header *header;

    if (str == NULL)
        return;
    header = PKSTR_H_PTR(str);
    for (pkstr_uint_t i = header->length; i > 0; i--) {
        if (str[i - 1] == byte) {
            pkstr_remove_byte(str, i - 1);
            return;
        }
    }
}

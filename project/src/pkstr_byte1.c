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

void pkstr_push(pkstr_t *str, char byte)
{
    struct pkstr_header *header;
    pkstr_uint_t new_length;

    if (str == NULL)
        return;
    header = PKSTR_H_PTR(*str);
    new_length = header->length + 1;
    if (new_length > header->capacity)
        *str = i_pkstr_get_new_extend(
                *str, i_pkstr_recompute_capacity(new_length));
    if (*str == NULL)
        return;
    (*str)[new_length - 1] = byte;
    header = PKSTR_H_PTR(*str);
    header->length = new_length;
}

void pkstr_pop(const pkstr_t str)
{
    struct pkstr_header *header;

    if (str == NULL)
        return;
    header = PKSTR_H_PTR(str);
    if (header->length == 0)
        return;
    header->buffer[header->length - 1] = '\0';
    header->length--;
}

void pkstr_insert_byte(pkstr_t *str, char byte, pkstr_uint_t index)
{
    struct pkstr_header *header;
    pkstr_uint_t new_length;

    if (str == NULL)
        return;
    header = PKSTR_H_PTR(*str);
    if (index > header->length)
        index = header->length;
    new_length = header->length + 1;
    if (new_length > header->capacity)
        *str = i_pkstr_get_new_extend(
                *str, i_pkstr_recompute_capacity(new_length));
    if (*str == NULL)
        return;
    header = PKSTR_H_PTR(*str);
    for (pkstr_uint_t i = header->length; i > index; i--)
        (*str)[i] = (*str)[i - 1];
    (*str)[index] = byte;
    header->length = new_length;
}

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
#include <string.h>

#include "pkstr_internals.h"
#include "pkstr_types.h"

void pkstr_destroy(pkstr *str)
{
    struct pkstr_header *header;

    if (!str || !*str)
        return;
    header = PKSTR_H_PTR(*str);
    free(header);
}

void pkstr_clear(pkstr str)
{
    struct pkstr_header *header;

    if (!str)
        return;
    header = PKSTR_H_PTR(str);
    memset(header->buffer, 0, header->length);
    header->length = 0;
}

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

#ifndef PKSTR_SIMPLE_H
    #define PKSTR_SIMPLE_H

    #include "pkstr_types.h"

pkstr_uint_t pkstr_len(const pkstr str);
void pkstr_cat(pkstr *str1, const pkstr str2);
void pkstr_ncat(pkstr *str1, const pkstr str2, pkstr_uint_t n);
void pkstr_insert(pkstr *str1, const pkstr str2, pkstr_uint_t index);
void pkstr_trim_start(pkstr str, const char *bytes);
void pkstr_trim_end(pkstr str, const char *bytes);
void pkstr_remove(
    const pkstr str, pkstr_uint_t index_start, pkstr_uint_t index_end);
void pkstr_to_upper(const pkstr str);
void pkstr_to_lower(const pkstr str);

#endif /* PKSTR_SIMPLE_H */

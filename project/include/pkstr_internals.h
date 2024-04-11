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

#ifndef PKSTR_INTERNALS_H
    #define PKSTR_INTERNALS_H

    #include "pkstr_types.h"

    #define PKSTR_H_SIZE        (sizeof(struct pkstr_header))
    #define PKSTR_H_PTR(str)    ((struct pkstr_header *)(str - PKSTR_H_SIZE))

    #define CAPACITY_INCREASE_FACTOR    2
    #define MAX_CAPACITY        ((pkstr_uint_t)1 << (PKSTR_HEADER_TYPE - 1))
    #define BASE_CAPACITY       PKSTR_HEADER_TYPE

pkstr_uint_t i_pkstr_recompute_capacity(pkstr_uint_t value);
char *i_pkstr_new_from_raw_parts(
    pkstr_uint_t len, pkstr_uint_t capacity, const char *str);
struct pkstr_header *i_pkstr_header_new(
    pkstr_uint_t len, pkstr_uint_t capacity, const char *str);
pkstr_t i_pkstr_get_new_extend(pkstr_t str, pkstr_uint_t new_capacity);

#endif /* PKSTR_INTERNALS_H */

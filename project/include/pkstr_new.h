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

#ifndef PKSTR_NEW_H
    #define PKSTR_NEW_H

    #include "pkstr_types.h"

pkstr_t pkstr_new(const char *str);
pkstr_t pkstr_new_with_capacity(const char *str, pkstr_uint_t capacity);
pkstr_t pkstr_new_empty(void);
pkstr_t pkstr_new_from_pkstr(const pkstr_t str);
pkstr_t pkstr_repeat(const char *str, pkstr_uint_t count);

#endif /* PKSTR_NEW_H */

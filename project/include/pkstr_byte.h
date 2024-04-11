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

#ifndef PKSTR_BYTE_H
    #define PKSTR_BYTE_H

    #include "pkstr_types.h"

void pkstr_push(pkstr_t *str, char byte);
void pkstr_pop(const pkstr_t str);
void pkstr_insert_byte(pkstr_t *str, char byte, pkstr_uint_t index);
void pkstr_remove_byte(const pkstr_t str, pkstr_uint_t index);
int pkstr_lfind_byte(const pkstr_t str, char byte);
int pkstr_rfind_byte(const pkstr_t str, char byte);
void pkstr_lremove_byte(const pkstr_t str, char byte);
void pkstr_rremove_byte(const pkstr_t str, char byte);

#endif /* PKSTR_BYTE_H */

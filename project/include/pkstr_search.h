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

#ifndef PKSTR_SEARCH_H
    #define PKSTR_SEARCH_H

    #include <stdio.h>
    #include <stdbool.h>

    #include "pkstr_types.h"

bool pkstr_starts_with(const pkstr_t str, const char *prefix);
bool pkstr_ends_with(const pkstr_t str, const char *suffix);
bool pkstr_contains(const pkstr_t str, const char *substr);
ssize_t pkstr_lsearch(const pkstr_t str, const char *substr);
ssize_t pkstr_rsearch(const pkstr_t str, const char *substr);

#endif /* PKSTR_SEARCH_H */

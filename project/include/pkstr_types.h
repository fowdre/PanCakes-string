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

#ifndef PKSTR_TYPES_H
    #define PKSTR_TYPES_H

    #include <stdint.h>

    #define PKSTR_HEADER_TYPE_TINY  8
    #define PKSTR_HEADER_TYPE_SMALL 16
    #define PKSTR_HEADER_TYPE_MEDIUM 32
    #define PKSTR_HEADER_TYPE_LARGE 64

    #define PKSTR_HEADER_TYPE   PKSTR_HEADER_TYPE_MEDIUM

    #if PKSTR_HEADER_TYPE % 8 != 0
        #error "PKSTR_HEADER_TYPE must be a multiple of 8"
    #endif
    #if PKSTR_HEADER_TYPE < 8
        #error "PKSTR_HEADER_TYPE must be at least 8"
    #endif
    #if PKSTR_HEADER_TYPE > 64
        #error "PKSTR_HEADER_TYPE must be at most 64"
    #endif

    #if PKSTR_HEADER_TYPE == 8
typedef uint8_t pkstr_uint_t;
    #elif PKSTR_HEADER_TYPE == 16
typedef uint16_t pkstr_uint_t;
    #elif PKSTR_HEADER_TYPE == 32
typedef uint32_t pkstr_uint_t;
    #elif PKSTR_HEADER_TYPE == 64
typedef uint64_t pkstr_uint_t;
    #endif

    #if defined(__GNUC__)
        #define PKSTR_MAYBE_UNUSED  __attribute__((unused))
        #define PKSTR_PACKED        __attribute__((packed))
    #else
        #error "Unsupported compiler"
    #endif

struct PKSTR_PACKED pkstr_header {
    pkstr_uint_t capacity;
    pkstr_uint_t length;
    char buffer[];
};

typedef char *pkstr_t;

#endif /* PKSTR_TYPES_H */

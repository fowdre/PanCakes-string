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

#include "pkstr_types.h"
#include "pkstr_internals.h"
#include "pkstr_new.h"
#include "pkstr_destroy.h"

struct str_cpy_info {
    char *str;
    char *p;
};

bool pkstr_is_empty(const pkstr str)
{
    const struct pkstr_header *header;

    if (str == NULL)
        return true;
    header = PKSTR_H_PTR(str);
    return header->length == 0;
}

static bool pkstr_split_i_realloc_failure_cleanup(
    pkstr *pkstr_array, size_t pkstr_array_size, char *cpy_p)
{
    free(cpy_p);
    for (size_t i = 0; i < pkstr_array_size; i++)
        pkstr_destroy(pkstr_array[i]);
    free(pkstr_array);
    return false;
}

static bool pkstr_split_i_loop(pkstr **result,
    size_t *arr_size, const char *bytes, struct str_cpy_info* str_cpy_info)
{
    const char *token = strtok_r(str_cpy_info->str, bytes, &str_cpy_info->str);
    pkstr *tmp;

    while (token != NULL) {
        tmp = realloc(*result, sizeof(pkstr) * (*arr_size + 1));
        if (tmp == NULL) {
            pkstr_split_i_realloc_failure_cleanup(
                *result, *arr_size, str_cpy_info->p);
            return false;
        }
        *result = tmp;
        (*result)[*arr_size] = pkstr_new(token);
        (*arr_size)++;
        token = strtok_r(str_cpy_info->str, bytes, &str_cpy_info->str);
    }
    return true;
}

static bool pkstr_split_i_null_append(
    pkstr **result, size_t arr_size, char *cpy_p)
{
    pkstr *tmp = realloc(*result, sizeof(pkstr) * (arr_size + 1));

    if (tmp == NULL) {
        pkstr_split_i_realloc_failure_cleanup(*result, arr_size, cpy_p);
        return false;
    }
    tmp[arr_size] = NULL;
    *result = tmp;
    return true;
}

pkstr* pkstr_split(const pkstr str, const char *bytes)
{
    char *str_cpy;
    char *cpy_p;
    pkstr *result = NULL;
    size_t arr_size = 0;

    if (str == NULL || bytes == NULL)
        return NULL;
    str_cpy = strdup(str);
    if (str_cpy == NULL)
        return NULL;
    cpy_p = str_cpy;
    if (pkstr_split_i_loop(&result,
            &arr_size, bytes, &(struct str_cpy_info){str_cpy, cpy_p}) == false)
        return NULL;
    if (pkstr_split_i_null_append(&result, arr_size, cpy_p) == false)
        return NULL;
    free(cpy_p);
    return result;
}

static void pkstr_range_i_checks(
    const struct pkstr_header *header, int64_t *start, int64_t *end)
{
    if (*start < 0)
        *start = header->length + *start + 1;
    if (*end < 0)
        *end = header->length + *end + 1;
    if (*start >= header->length)
        *start = header->length;
    if (*end >= header->length)
        *end = header->length;
    if (*start > *end)
        *start = *end;
}

pkstr pkstr_range(const pkstr str, int64_t start, int64_t end)
{
    const struct pkstr_header *header;
    pkstr result;
    pkstr_uint_t result_len;

    if (str == NULL)
        return NULL;
    header = PKSTR_H_PTR(str);
    if (header->length == 0)
        return pkstr_new_empty();
    header = PKSTR_H_PTR(str);
    pkstr_range_i_checks(header, &start, &end);
    result_len = (pkstr_uint_t)(end - start);
    result = pkstr_new_with_capacity(
                "", i_pkstr_recompute_capacity(result_len));
    if (result == NULL)
        return NULL;
    memcpy(result, str + start, result_len);
    return result;
}

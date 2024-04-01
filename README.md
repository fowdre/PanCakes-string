# pan\<C\>akes\<🥞\> string

Part of the pan<C\>akes<🥞> collection, aimed to provide tools to help with C programming.

pan\<C\>akes\<🥞\> string is an implementation of a heap-allocated string.

![Test code coverage summary report](https://github.com/fowdre/panCakes-string/actions/workflows/test_coverage_summary_report.yml/badge.svg)

<!-- GENERATED COVERAGE START -->
![Code Coverage](https://img.shields.io/badge/Code%20Coverage-98%25-success?style=flat)

Package | Line Rate | Branch Rate | Complexity | Health
-------- | --------- | ----------- | ---------- | ------
project.src | 98% | 96% | 0 | ✔
**Summary** | **98%** (117 / 120) | **96%** (73 / 76) | **0** | ✔

_Minimum allowed line rate is `80%`_
<!-- GENERATED COVERAGE END -->

## Functions left to implement:

### String new

- [X] pkstr_new() | creates a new string
- [X] pkstr_new_with_capacity() | creates a new string with a given capacity
- [X] pkstr_new_empty() | creates a new empty string
- [X] pkstr_new_from_pkstr() | creates a new string from another string
- [X] pkstr_repeat() | creates a new string from repeating the given string a given number of times

### String 'destruction'

- [X] pkstr_free() | frees the string
- [X] pkstr_clear() | clears the string but keeps the capacity
- [ ] ~~pkstr_reset() | clears the string and sets the capacity to 0~~

### String comparison and search functions

- [X] pkstr_equals() | returns true if the strings' capacities, lengths, and buffers are equal
- [X] pkstr_partial_equals() | returns true if strings' buffers are equal
- [X] pkstr_starts_with() | returns true if the string starts with the given string
- [X] pkstr_ends_with() | returns true if the string ends with the given string
- [X] pkstr_contains() | returns true if the string contains the given string
- [X] pkstr_lsearch() | searches for the given string in the string and returns the index, starting from the left
- [X] pkstr_rsearch() | searches for the given string in the string and returns the index, starting from the right

### Simple string operations

- [ ] pkstr_len() | returns the length of the string
- [ ] pkstr_cat() | concatenates two strings
- [ ] pkstr_ncat() | concatenates two strings up to a given length
- [ ] pkstr_insert() | insert a string at the given index
- [ ] pkstr_trim() | trim the string using the given bytes
- [ ] pkstr_truncate() | truncates the string at the given index
- [ ] pkstr_to_upper() | converts the string to uppercase
- [ ] pkstr_to_lower() | converts the string to lowercase

### Other string operations

- [ ] pkstr_is_empty() | returns true if the string is empty, false otherwise
- [ ] pkstr_split() | splits the string using the given bytes
- [ ] pkstr_range() | returns a new string of the given range
- [ ] pkstr_shrink() | shrinks the string to fit the length
- [ ] pkstr_shrink_to() | shrinks the string to fit the given length
- [ ] pkstr_filter() | filters the string using the given function
- [ ] pkstr_map() | maps the string using the given function

### Bytes operations

- [ ] pkstr_push() | push a byte to the string
- [ ] pkstr_pop() | pop the byte from the string
- [ ] pkstr_insert_byte() | insert a byte at the given index
- [ ] pkstr_remove_byte() | remove the byte at the given index
- [ ] pkstr_lfind_byte() | find a byte, starting from the left
- [ ] pkstr_rfind_byte() | find a byte, starting from the right
- [ ] pkstr_lremove_byte() | remove a byte, starting from the left
- [ ] pkstr_rremove_byte() | remove a byte, starting from the right

### String conversion

- [ ] pkstr_into_int8() | parse the string into an int8_t
- [ ] pkstr_into_int16() | parse the string into an int16_t
- [ ] pkstr_into_int32() | parse the string into an int32_t
- [ ] pkstr_into_int64() | parse the string into an int64_t
- [ ] pkstr_into_uint8() | parse the string into an uint8_t
- [ ] pkstr_into_uint16() | parse the string into an uint16_t
- [ ] pkstr_into_uint32() | parse the string into an uint32_t
- [ ] pkstr_into_uint64() | parse the string into an uint64_t
- [ ] pkstr_into_float() | parse the string into a float
- [ ] pkstr_into_double() | parse the string into a double
- [ ] pkstr_from_int8() | convert an int8_t into a string
- [ ] pkstr_from_int16() | convert an int16_t into a string
- [ ] pkstr_from_int32() | convert an int32_t into a string
- [ ] pkstr_from_int64() | convert an int64_t into a string
- [ ] pkstr_from_float() | convert a float into a string
- [ ] pkstr_from_double() | convert a double into a string

### String internals

- [ ] i_pkstr_set_buffer() | sets the buffer of the string
- [ ] i_pkstr_set_len() | sets the length of the string
- [ ] i_pkstr_set_capacity() | sets the capacity of the string
- [ ] i_pkstr_get_buffer() | gets the buffer of the string
- [ ] i_pkstr_get_len() | gets the length of the string
- [ ] i_pkstr_get_capacity() | gets the capacity of the string
- [ ] i_pkstr_set_header() | sets the header of the string
- [ ] i_pkstr_get_header() | gets the header of the string

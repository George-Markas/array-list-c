#pragma once

#include <stddef.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 4
#define BYTE_CAPACITY (array_list->capacity * array_list->element_size)
#define DATA_OFFSET (array_list->data + (array_list->length * array_list->element_size))
#define FREE(ptr) free(ptr); ptr = NULL

typedef struct ArrayList {
    void* data;
    size_t length;       // Current number of elements
    size_t capacity;     // Max number of elements
    size_t element_size; // The byte size an element
} AList_t;


AList_t* array_list_new(size_t element_size);

bool array_list_add(AList_t* array_list, const void* val);

void array_list_delete(AList_t* array_list);

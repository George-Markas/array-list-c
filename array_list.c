#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AList_t* array_list_new(size_t element_size) {
    AList_t* new_array_list = malloc(sizeof(AList_t));
    if(element_size < 1) element_size = 1;
    new_array_list->data = malloc(INITIAL_CAPACITY * element_size);
    if(new_array_list->data == NULL) {
        FREE(new_array_list);
        return NULL;
    }

    new_array_list->length = 0;
    new_array_list->capacity = INITIAL_CAPACITY;
    new_array_list->element_size = element_size;

    return new_array_list;
}

bool array_list_add(AList_t* array_list, const void* val) {
    if(array_list == NULL) return false;
    if(array_list->length + 1 > array_list->capacity) {
        void* new_ptr = realloc(array_list->data, BYTE_CAPACITY * 2);
        if(new_ptr == NULL) return false;
        array_list->data = new_ptr;
        array_list->capacity *= 2;
    }

    memcpy(DATA_OFFSET, (void*) val, array_list->element_size);
    array_list->length++;
    return true;
}

void array_list_delete(AList_t* array_list) {
    if(array_list == NULL) return;
    FREE(array_list->data);
    FREE(array_list);
}

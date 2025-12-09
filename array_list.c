#include "array_list.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

AList_t* array_list_new(const size_t element_size) {
    AList_t* new_array_list = malloc(sizeof(AList_t));
    new_array_list->data = calloc(INITIAL_CAPACITY, element_size);
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
        // Attempt to expand so it fits...
        return false;
    }

    memcpy(DATA_OFFSET, (void *) val, array_list->element_size);
    array_list->length++;
    return true;
}

void array_list_delete(AList_t* array_list) {
    if(array_list == NULL) return;
    FREE(array_list->data);
    FREE(array_list);
}

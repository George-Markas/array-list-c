#include <stdio.h>
#include "array_list.h"

typedef struct FavouriteNumber {
    double num;
    const char* name;
} fave_num_t;

int main(void) {
    AList_t* array_list = array_list_new(sizeof(fave_num_t));

    const fave_num_t pi = {.num = 3.14159, .name = "pi"};
    const fave_num_t e = {.num = 2.71828, .name = "e"};
    const fave_num_t phi = {.num = 1.61803, .name = "phi"};
    const fave_num_t tau = {.num = 6.28318, .name = "tau"};
    const fave_num_t g = {.num = 0.83462, .name = "g"};

    printf("-- Pre expansion capacity: %zu --\n", array_list->capacity);

    array_list_add(array_list, &pi);
    array_list_add(array_list, &e);
    array_list_add(array_list, &phi);
    array_list_add(array_list, &tau);
    array_list_add(array_list, &g); // Should automatically expand here

    printf("%s: %f\n", ((fave_num_t *) array_list->data + 0)->name, ((fave_num_t *) array_list->data + 0)->num);
    printf("%s: %f\n", ((fave_num_t *) array_list->data + 1)->name, ((fave_num_t *) array_list->data + 1)->num);
    printf("%s: %f\n", ((fave_num_t *) array_list->data + 2)->name, ((fave_num_t *) array_list->data + 2)->num);
    printf("%s: %f\n", ((fave_num_t *) array_list->data + 3)->name, ((fave_num_t *) array_list->data + 3)->num);
    printf("%s: %f\n", ((fave_num_t *) array_list->data + 4)->name, ((fave_num_t *) array_list->data + 3)->num);

    printf("-- Post expansion capacity: %zu --\n", array_list->capacity);

    array_list_delete(array_list);
    return 0;
}
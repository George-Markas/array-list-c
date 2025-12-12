# Array List

This is an implementation of an array list in C.
Check the header for the related functions.

## Example
```c
#include <stdio.h>
#include "array_list.h"

typedef struct MathConstant {
    double num;
    const char* name;
} num_t;

void print_contents(const AList_t* array_list);

int main(void) {
    AList_t* array_list = array_list_new(sizeof(num_t));

    const num_t pi = {.num = 3.14159, .name = "pi"};
    const num_t e = {.num = 2.71828, .name = "e"};
    const num_t phi = {.num = 1.61803, .name = "phi"};
    const num_t tau = {.num = 6.28318, .name = "tau"};
    const num_t g = {.num = 0.83462, .name = "g"};

    // Append the structs
    array_list_add(array_list, &pi);
    array_list_add(array_list, &e);
    array_list_add(array_list, &phi);
    array_list_add(array_list, &tau);
    array_list_add(array_list, &g); // Should expand here
    print_contents(array_list);

    // Remove 3 elements
    array_list_remove(array_list);
    array_list_remove(array_list);
    array_list_remove(array_list); // Should shrink here
    print_contents(array_list);

    // Overwrite e with phi
    array_list_set(array_list, 1, &phi);
    print_contents(array_list);

    // Free everything
    array_list_delete(array_list);

    return 0;
}

void print_contents(const AList_t* array_list) {
    for(size_t i = 0; i < array_list->length; i++) {
        printf("[%zu] %s: %g\n", i, ((num_t *) array_list_get(array_list, i))->name,
               ((num_t *) array_list_get(array_list, i))->num);
    }
    printf("-- capacity: %zu --\n\n", array_list->capacity);
}
```

## Using in a project
You can install the library with the included Makefile:
```sh
git clone https://github.com/George-Markas/Array_List.git
cd Array_List
sudo make install
```

To link against it:
```sh
cc hello.c -larray_list -o hello
```

To uninstall it:
```
sudo make clean uninstall
```


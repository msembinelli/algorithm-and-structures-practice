/*
 * main.c
 * This file tests the implementation of the resizable array.
 *
 * Matthew Sembinelli
 * December 24, 2016
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "resizing_array.h"

void print_item(int item)
{
    printf("item: %d\n", item);
    fflush(stdout);
}

void print_array(r_array* arr)
{
    if(is_empty(arr))
    {
        printf("(empty)\n");
        return;
    }
    for(int i = 0; i < size(arr); i++)
    {
        printf("| %d ", at(arr, i));
    }
    printf("|\n");
    fflush(stdout);
}

int main(void)
{
    r_array* arr = init();

    push(arr, 1);
    insert(arr, 1, 11);
    prepend(arr, 0);
    push(arr, 2);
    push(arr, 3);
    insert(arr, 4, 22);
    insert(arr, 5, 66);

    print_array(arr);

    print_item(pop(arr));

    print_array(arr);

    prepend(arr, 1000);

    print_array(arr);

    push(arr, 1);
    insert(arr, 1, 11);
    prepend(arr, 0);
    push(arr, 2);
    push(arr, 3);
    insert(arr, 4, 22);
    push(arr, 2);
    push(arr, 3);
    insert(arr, 4, 22);
    push(arr, 0xFF);

    print_array(arr);

    remove_item(arr, 22);

    print_array(arr);

    print_item(find(arr, 6666));

    remove_item(arr, 0);
    remove_item(arr, 2);
    remove_item(arr, 0xFF);

    print_array(arr);

    destroy(arr);

    return 0;
}

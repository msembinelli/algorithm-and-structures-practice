/*****************************************************************************
 * main.c
 * This file tests the implementation of the resizable array.
 *
 * Matthew Sembinelli
 * December 24, 2016
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "resizing_array.h"

/*****************************************************************************
 *                                Definitions                                *
 *****************************************************************************/
void print(int data)
{
    printf("print: %d\n", data);
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

    print(capacity(arr));

    insert(arr, 0, 1);

    print_array(arr);

    push(arr, 1);
    insert(arr, 1, 11);
    prepend(arr, 0);
    push(arr, 2);
    push(arr, 3);
    insert(arr, 4, 22);
    insert(arr, 5, 66);

    print_array(arr);

    print(pop(arr));

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

    print(find(arr, 6666));

    print(capacity(arr));

    remove_item(arr, 0);
    remove_item(arr, 2);
    remove_item(arr, 0xFF);

    print(capacity(arr));

    print_array(arr);

    delete(arr, 0);
    delete(arr, 0);
    delete(arr, 0);
    delete(arr, 0);

    print_array(arr);
    print(size(arr));

    print(at(arr, 2));

    delete(arr, 0);
    delete(arr, 0);
    delete(arr, 0);
    delete(arr, 0);

    print(capacity(arr));

    print_array(arr);

    pop(arr);

    print_array(arr);

    destroy(arr);

    return 0;
}

/*
 * resizing_array.c
 * This file implements the various methods of a dynamically resizable array.
 *
 * Matthew Sembinelli
 * December 24, 2016
 */

#include <assert.h>
#include <string.h>
#include "resizing_array.h"

#define INIT_CAPACITY ( 16 )
#define RESIZE_FACTOR ( 2 ) // Size to increase/decrease the dynamic capacity of the array
#define DECREASE_TRIGGER ( 4 ) // When size is 1/4 of the capacity, shrink the dynamic capacity

// Private function prototypes
static void resize(r_array* arr, int new_capacity);

// Public function definitions
r_array* init(void)
{
    r_array* return_arr = (r_array*) malloc(sizeof(r_array));
    int* buffer = (int*) malloc(sizeof(int)*INIT_CAPACITY);
    return_arr->data = buffer;
    return_arr->size = 0;
    return_arr->capacity = INIT_CAPACITY;
    return return_arr;
}

int size(r_array* arr)
{
    return arr->size;
}

int capacity(r_array* arr)
{
    return arr->capacity;
}

bool is_empty(r_array* arr)
{
    return (0 == arr->size);
}

int at(r_array* arr, int index)
{
    // blow up if the index is OOB
    assert((index < arr->size) && (index >= 0));
    return *(arr->data + index);
}

void push(r_array* arr, int item)
{
    if(arr->size == arr->capacity)
    {
        resize(arr, (arr->capacity * RESIZE_FACTOR));
    }

    *(arr->data + arr->size) = item;
    arr->size++;
}

void insert(r_array* arr, int index, int item)
{
    // blow up if the index is OOB
    assert((index <= arr->size) && (index >= 0));

    if(arr->size == arr->capacity)
    {
        resize(arr, (arr->capacity * RESIZE_FACTOR));
    }

    memmove(arr->data + index + 1, arr->data + index, (arr->size - index) * sizeof(int));
    *(arr->data + index) = item;
    arr->size++;
}

void prepend(r_array* arr, int item)
{
    // Prepend is the same as inserting at index 0
    insert(arr, 0, item);
}

int pop(r_array* arr)
{
    int return_item = *(arr->data + arr->size - 1);
    arr->size--;

    if(arr->size * DECREASE_TRIGGER == arr->capacity  && arr->capacity > INIT_CAPACITY)
    {
        resize(arr, (arr->capacity / RESIZE_FACTOR));
    }

    return return_item;
}

void delete(r_array* arr, int index)
{
    // blow up if the index is OOB
    assert((index < arr->size) && (index >= 0));

    memmove(arr->data + index, arr->data + index + 1, (arr->size - index) * sizeof(int));
    arr->size--;

    if(arr->size * DECREASE_TRIGGER == arr->capacity && arr->capacity > INIT_CAPACITY)
    {
        resize(arr, (arr->capacity / RESIZE_FACTOR));
    }
}

int find(r_array* arr, int item)
{
    for(int index = 0; index < arr->size; index++)
    {
        if(*(arr->data + index) == item)
        {
            return index;
        }
    }
    return -1;
}

void remove_item(r_array* arr, int item)
{
    int item_occurred = 0;
    for(int index = 0; index < arr->size; index++)
    {
        if(*(arr->data + index) == item)
        {
            item_occurred++;
        }
    }

    while(item_occurred--)
    {
        delete(arr, find(arr, item));
    }
}

void destroy(r_array* arr)
{
    free(arr->data);
    free(arr);
    arr = NULL;
}

static void resize(r_array* arr, int new_capacity)
{
    arr->data = (int*) realloc(arr->data, sizeof(int) * new_capacity);
    arr->capacity = new_capacity;
}


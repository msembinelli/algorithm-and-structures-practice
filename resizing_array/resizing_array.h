/*
 * resizing_array.h
 * Public function prototypes for dynamically resizable array.
 *
 * Matthew Sembinelli
 * December 24, 2016
 */

#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int* data;
    int size;
    int capacity;
} r_array;

// Public function protoypes
r_array* init(void);
int size(r_array* arr);
int capacity(r_array* arr);
bool is_empty(r_array* arr);
int at(r_array* arr, int index);
void push(r_array* arr, int item);
void insert(r_array* arr, int index, int item);
void prepend(r_array* arr, int item);
int pop(r_array* arr);
void delete(r_array* arr, int index);
int find(r_array* arr, int item);
void remove_item(r_array* arr, int item);
void destroy(r_array* arr);

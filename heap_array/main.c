/*****************************************************************************
 * main.c
 * This file tests and implements a max heap with an array.
 *
 * Matthew Sembinelli
 * January 11, 2017
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#define HEAP_MAX_SIZE 256

/*****************************************************************************
 *                                Definitions                                *
 *****************************************************************************/
void insert_max_heap(int* heap, int* heap_size, int value)
{
    // Append to end
    if(*heap_size != HEAP_MAX_SIZE)
    {
        heap[*heap_size] = value;
    }

    // Bubble up
    int parent_index = (*heap_size - 1) / 2;
    int current_index = *heap_size;
    while(heap[parent_index] < value)
    {
        int tmp = heap[parent_index];
        heap[parent_index] = heap[current_index];
        heap[current_index] = tmp;
        current_index = parent_index;
        parent_index /= 2;
    }
    (*heap_size)++;
}

int remove_max_heap(int* heap, int* heap_size)
{
    int max;
    if(*heap_size != 0)
    {
        max = heap[0];
        heap[0] = heap[*heap_size - 1];
    }
    else
    {
        assert(*heap_size);
    }

    // Bubble down
    int current_index = 0;
    int child_index = 1;
    while(heap[child_index] > heap[current_index] && heap[child_index + 1] > heap[current_index])
    {
        // Choose bigger child to swap with
        child_index = (heap[child_index] > heap[child_index + 1]) ? child_index : child_index + 1;
        int tmp = heap[child_index];
        heap[child_index] = heap[current_index];
        heap[current_index] = tmp;
        current_index = child_index;
        child_index *= 2;
    }
    (*heap_size)--;
    return max;
}

void print_array(int* arr, int size)
{
    int i = 0;
    for(; i<size; i++)
    {
        printf("%d | ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int heap[HEAP_MAX_SIZE];
    int heap_size = 0;

    printf("max size of heap: %d\n", sizeof(heap) / sizeof(*heap));

    insert_max_heap(heap, &heap_size, 20);
    insert_max_heap(heap, &heap_size, 10);
    insert_max_heap(heap, &heap_size, 50);
    insert_max_heap(heap, &heap_size, 3);
    print_array(heap, heap_size);
    insert_max_heap(heap, &heap_size, 8);
    insert_max_heap(heap, &heap_size, 5);
    insert_max_heap(heap, &heap_size, 3);
    insert_max_heap(heap, &heap_size, 1);
    insert_max_heap(heap, &heap_size, 100);

    print_array(heap, heap_size);

    printf("Removing element: %d\n", remove_max_heap(heap, &heap_size));
    print_array(heap, heap_size);

    printf("Removing element: %d\n", remove_max_heap(heap, &heap_size));
    print_array(heap, heap_size);

    printf("Removing element: %d\n", remove_max_heap(heap, &heap_size));
    print_array(heap, heap_size);

    return 0;
}

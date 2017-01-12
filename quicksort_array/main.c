/*****************************************************************************
 * main.c
 * This file tests and implements quick sort with an array.
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

/*****************************************************************************
 *                                Definitions                                *
 *****************************************************************************/
void print_array(int* arr, int size)
{
    int i = 0;
    for(; i<size; i++)
    {
        printf("%d | ", arr[i]);
    }
    printf("\n");
}

void swap(int* arr, int first, int second)
{
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}

int partition(int* arr, int start, int end)
{
    //swap until everything > pivot is on the right and everything <= is on the left
    int pivot_value = arr[end];
    int i;
    int j = start;
    for(i = start; i <= end - 1; i++)
    {
        if(arr[i] <= pivot_value)
        {
            swap(arr, i, j);
            j++;
        }
    }
    swap(arr, end, j);
    return j;
}

void quicksort(int* arr, int start, int end)
{
    if(start >= end) return;

    int p = partition(arr, start, end);
    quicksort(arr, start, p-1);
    quicksort(arr, p+1, end);
}

int main(void)
{
    int array[] = { 5, 2, 1, 20, 70, -20, 30, 22, 6, 7, 8, 11, 0, 0 };

    int size = sizeof(array) / sizeof(*array);

    print_array(array, size);

    quicksort(array, 0, size - 1);

    print_array(array, size);

    return 0;
}

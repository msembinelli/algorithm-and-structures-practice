/*****************************************************************************
 * main.c
 * This file tests and implements merge sort with an array.
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
int array[14] = { 5, 2, 1, 20, 70, -20, 30, 22, 6, 7, 8, 11, 0, 0 };
int merge_array[14];

void print_array(int* arr, int size)
{
    int i = 0;
    for(; i<size; i++)
    {
        printf("%d | ", arr[i]);
    }
    printf("\n");
}

void merge(int lo, int mid, int hi)
{
    int i = lo;
    int j = mid + 1;
    int k = lo;
    while(i <= mid && j <= hi)
    {
        if(array[i] <= array[j])
        {
            merge_array[k] = array[i++];
        }
        else
        {
            merge_array[k] = array[j++];
        }
        k++;
    }
    // Take care of last elements
    while(i <= mid)
    {
        merge_array[k++] = array[i++];
    }
    while(j <= hi)
    {
        merge_array[k++] = array[j++];
    }

    for(i = lo; i <= hi; i++)
    {
        array[i] = merge_array[i];
    }
}

void mergesort(int lo, int hi)
{
    if(lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergesort(lo, mid);
    mergesort(mid+1, hi);
    merge(lo, mid, hi);
}

int main(void)
{
    int size = sizeof(array) / sizeof(*array);

    print_array(array, size);
    mergesort(0, size - 1);
    print_array(array, size);

    return 0;
}

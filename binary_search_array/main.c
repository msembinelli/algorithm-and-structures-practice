/*****************************************************************************
 * main.c
 * This file tests and implements binary search on a sorted array.
 *
 * Matthew Sembinelli
 * January 1, 2017
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
int binary_search_recursive(int* arr, int lo, int hi, int target)
{
    // Null check
    assert(arr);

    if(lo > hi)
    {
        // Not found in this division
        return -1;
    }

    int mid = ((hi - lo) / 2) + lo;
    if(target == arr[mid])
    {
        return mid;
    }
    else if(target > arr[mid])
    {
        lo = mid + 1;
    }
    else
    {
        hi = mid - 1;
    }

    return binary_search_recursive(arr, lo, hi, target);
}

int binary_search(int* arr, int size, int target)
{
    // Null and size check
    assert(arr && size > 0);

    int lo = 0;
    int hi = size - 1;
    int mid = 0;

    while(lo <= hi)
    {
        mid = ((hi - lo) / 2) + lo;
        if(target == arr[mid])
        {
            return mid;
        }
        else if(target > arr[mid])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return -1;
}

int main(void)
{
    // Declare sorted array
    int x[] = {0,1,2,3,4,6,7,8,9};

    printf("Finding index of item: %d\n", 6);
    int element_index = binary_search(x, sizeof(x)/sizeof(*x), 6);
    if(element_index >= 0)
    {
        printf("Found element index: %d\n", element_index);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Finding index of item: %d\n", 10);
    element_index = binary_search(x, sizeof(x)/sizeof(*x), 10);
    if(element_index >= 0)
    {
        printf("Found element index: %d\n", element_index);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Finding index of item: %d\n", 5);
    element_index = binary_search(x, sizeof(x)/sizeof(*x), 5);
    if(element_index >= 0)
    {
        printf("Found element index: %d\n", element_index);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Finding index of item (recursive): %d\n", 6);
    element_index = binary_search_recursive(x, 0, sizeof(x)/sizeof(*x) - 1, 6);
    if(element_index >= 0)
    {
        printf("Found element index: %d\n", element_index);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Finding index of item (recursive): %d\n", 10);
    element_index = binary_search_recursive(x, 0, sizeof(x)/sizeof(*x) - 1, 10);
    if(element_index >= 0)
    {
        printf("Found element index: %d\n", element_index);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Finding index of item (recursive): %d\n", -1);
    element_index = binary_search_recursive(x, 0, sizeof(x)/sizeof(*x) - 1, -1);
    if(element_index >= 0)
    {
        printf("Found element index: %d\n", element_index);
    }
    else
    {
        printf("Element not found\n");
    }

    printf("Finding index of item (recursive): %d\n", 5);
    element_index = binary_search_recursive(x, 0, sizeof(x)/sizeof(*x) - 1, 5);
    if(element_index >= 0)
    {
        printf("Found element index: %d\n", element_index);
    }
    else
    {
        printf("Element not found\n");
    }



    return 0;
}

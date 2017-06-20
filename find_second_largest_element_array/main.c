/*****************************************************************************
 * main.c
 * This file tests and implements finding the second largest element in an array.
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
int second_largest_element(int* arr, int size)
{
    if( arr == NULL)
    {
        assert(arr);
    }

    int max = arr[0];
    int second_max = arr[0];
    int i;
    for(i = 0; i < size; i++)
    {
        if(arr[i] < max && arr[i] > second_max)
        {
            second_max = arr[i];
        }
        if(arr[i] > max)
        {
            second_max = max;
            max = arr[i];
        }
    }
    return second_max;
}

int main(void)
{
    int array[] = { 5, 2, 1, 20, 70, -20, 30, 22, 6, 7, 8, 11, 0, 0 };

    int size = sizeof(array) / sizeof(*array);

    printf("Second largest element: %d\n", second_largest_element( array, size ));

    return 0;
}

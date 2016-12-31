/*****************************************************************************
 * main.c
 * This file tests the implementation of the linked list based queue.
 *
 * Matthew Sembinelli
 * December 31, 2016
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"

/*****************************************************************************
 *                                Definitions                                *
 *****************************************************************************/
int main(void)
{
    queue* q = init_queue();

    if(empty_queue(q))
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("NOT EMPTY\n");
    }

    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);

    if(empty_queue(q))
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("NOT EMPTY\n");
    }

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    if(empty_queue(q))
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("NOT EMPTY\n");
    }

    destroy_queue(q);

    return 0;
}

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
    queue* q = init(4);

    if(empty(q))
    {
        printf("EMPTY\n");
    }
    else if(full(q))
    {
        printf("FULL\n");
    }
    else
    {
        printf("NOT EMPTY\n");
    }
    fflush(stdout);

    printf("ENQUEUE: %d\n", 5);
    enqueue(q, 5);
    printf("ENQUEUE: %d\n", 6);
    enqueue(q, 6);

    if(empty(q))
    {
        printf("EMPTY\n");
    }
    else if(full(q))
    {
        printf("FULL\n");
    }
    else
    {
        printf("NOT EMPTY\n");
    }
    fflush(stdout);

    printf("ENQUEUE: %d\n", 7);
    enqueue(q, 7);
    printf("ENQUEUE: %d\n", 8);
    enqueue(q, 8);

    if(empty(q))
    {
        printf("EMPTY\n");
    }
    else if(full(q))
    {
        printf("FULL\n");
    }
    else
    {
        printf("NOT EMPTY\n");
    }
    fflush(stdout);

    printf("DEQUEUE: %d\n", dequeue(q));

    printf("ENQUEUE: %d\n", 7);
    enqueue(q, 7);

    if(!full(q))
    {
        enqueue(q, 8);
    }

    if(empty(q))
    {
        printf("EMPTY\n");
    }
    else if(full(q))
    {
        printf("FULL\n");
    }
    else
    {
        printf("NOT EMPTY\n");
    }
    fflush(stdout);

    printf("DEQUEUE: %d\n", dequeue(q));
    printf("DEQUEUE: %d\n", dequeue(q));
    printf("DEQUEUE: %d\n", dequeue(q));
    printf("DEQUEUE: %d\n", dequeue(q));

    if(empty(q))
    {
        printf("EMPTY\n");
    }
    else if(full(q))
    {
        printf("FULL\n");
    }
    else
    {
        printf("NOT EMPTY\n");
    }
    fflush(stdout);

    destroy(q);

    return 0;
}

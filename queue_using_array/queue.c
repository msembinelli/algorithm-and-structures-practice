/*****************************************************************************
 * queue.c
 * This file implements the various methods of an array based queue.
 *
 * Matthew Sembinelli
 * December 31, 2016
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <assert.h>
#include "queue.h"

/*****************************************************************************
 *                                  Types                                    *
 *****************************************************************************/
// Private queue structure
typedef struct
{
    int* buffer;
    int head;
    int tail;
    int size;
} queue_private;

/*****************************************************************************
 *                             Public Definitions                            *
 *****************************************************************************/
queue* init(int size)
{
    // Must be power of two to use enqueue and dequeue wrap around property
    assert(!(size % 2));

    queue_private* q_p = (queue_private*) malloc(sizeof(queue_private));
    q_p->buffer = (int*) malloc(sizeof(int) * size);
    q_p->head = -1;
    q_p->tail = -1;
    q_p->size = size;

    queue* q = (queue*) malloc(sizeof(queue));
    q->private = q_p;

    return q;
}

void enqueue(queue* q, int data)
{
    queue_private* q_p = q->private;

    // If queue is full, blow up
    assert(!full(q));

    q_p->head = (q_p->head + 1) & (q_p->size - 1);
    q_p->buffer[q_p->head] = data;
}

int dequeue(queue* q)
{
    queue_private* q_p = q->private;

    // If queue is empty, blow up
    assert(!empty(q));

    q_p->tail = (q_p->tail + 1) & (q_p->size - 1);
    int data = q_p->buffer[q_p->tail];
    return data;
}

bool empty(queue* q)
{
    queue_private* q_p = q->private;
    return (q_p->head == q_p->tail);
}

bool full(queue* q)
{
    queue_private* q_p = q->private;
    return ((q_p->head - q_p->size) == q_p->tail);
}

void destroy(queue* q)
{
    queue_private* q_p = q->private;
    free(q_p->buffer);
    q_p->buffer = NULL;
    free(q->private);
    q->private = NULL;
    free(q);
    q = NULL;
}


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
    int capacity;
} queue_private;

/*****************************************************************************
 *                             Public Definitions                            *
 *****************************************************************************/
queue* init(int capacity)
{
    // Must be power of two to use enqueue and dequeue wrap around property
    assert(!(capacity % 2));

    queue_private* q_p = (queue_private*) malloc(sizeof(queue_private));
    q_p->buffer = (int*) malloc(sizeof(int) * capacity);
    q_p->head = 0;
    q_p->tail = 0;
    q_p->size = 0;
    q_p->capacity = capacity;

    queue* q = (queue*) malloc(sizeof(queue));
    q->private = q_p;

    return q;
}

void enqueue(queue* q, int data)
{
    // Null check
    assert(q && q->private);

    queue_private* q_p = q->private;

    // If queue is full, blow up
    assert(!full(q));

    q_p->buffer[q_p->head] = data;
    q_p->head = (q_p->head + 1) & (q_p->capacity - 1);
    q_p->size++;
}

int dequeue(queue* q)
{
    // Null check
    assert(q && q->private);

    queue_private* q_p = q->private;

    // If queue is empty, blow up
    assert(!empty(q));

    int data = q_p->buffer[q_p->tail];
    q_p->tail = (q_p->tail + 1) & (q_p->capacity - 1);
    q_p->size--;
    return data;
}

bool empty(queue* q)
{
    // Null check
    assert(q && q->private);

    queue_private* q_p = q->private;
    return (!q_p->size);
}

bool full(queue* q)
{
    // Null check
    assert(q && q->private);

    queue_private* q_p = q->private;
    return (q_p->size == q_p->capacity);
}

void destroy(queue* q)
{
    // Null check
    assert(q && q->private);

    queue_private* q_p = q->private;
    free(q_p->buffer);
    q_p->buffer = NULL;
    free(q->private);
    q->private = NULL;
    free(q);
    q = NULL;
}


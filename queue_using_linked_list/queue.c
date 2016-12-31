/*****************************************************************************
 * queue.c
 * This file implements the various methods of a linked list based queue.
 *
 * Matthew Sembinelli
 * December 24, 2016
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <assert.h>
#include "linked_list_with_tail.h"
#include "queue.h"

/*****************************************************************************
 *                                  Types                                    *
 *****************************************************************************/
// Private queue structure
typedef struct
{
    linked_list* list;
} queue_private;

/*****************************************************************************
 *                             Public Definitions                            *
 *****************************************************************************/
queue* init_queue(void)
{
    queue_private* private_q = (queue_private*) malloc(sizeof(queue_private));

    // Initialize linked list contained in queue
    private_q->list = init();

    queue* q = (queue*) malloc(sizeof(queue));
    q->private = private_q;

    return q;
}

void enqueue(queue* q, int key)
{
    queue_private* private_q = q->private;
    push_back(private_q->list, key);
}

int dequeue(queue* q)
{
    queue_private* private_q = q->private;
    return pop_front(private_q->list);
}

bool empty_queue(queue* q)
{
    queue_private* private_q = q->private;
    return (empty(private_q->list));
}

void destroy_queue(queue* q)
{
    queue_private* private_q = q->private;
    destroy(private_q->list);
    free(q->private);
    q->private = NULL;
    free(q);
    q = NULL;
}


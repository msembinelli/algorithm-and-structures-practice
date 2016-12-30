/*****************************************************************************
 * linked_list_with_tail.h
 * Public function prototypes for singly linked list with a tail pointer.
 *
 * Matthew Sembinelli
 * December 24, 2016
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <stdlib.h>
#include <stdbool.h>

/*****************************************************************************
 *                                  Types                                    *
 *****************************************************************************/
// Public linked list structure
typedef struct
{
    void* private;
} linked_list;

/*****************************************************************************
 *                             Public Prototypes                             *
 *****************************************************************************/
linked_list* init(void);
void push_front(linked_list* list, int key);
int pop_front(linked_list* list);
void push_back(linked_list* list, int key);
int pop_back(linked_list* list);
int front(linked_list* list);
int back(linked_list* list);
void insert(linked_list* list, int index, int key);
void erase(linked_list* list, int index);
int value_at(linked_list* list, int index);
int value_n_from_end(linked_list* list, int n);
void reverse(linked_list* list);
void remove_value(linked_list* list, int key);
int get_size(linked_list* list);
bool empty(linked_list* list);
void destroy(linked_list* list);

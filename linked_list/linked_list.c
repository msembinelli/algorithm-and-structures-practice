/*
 * linked_list.c
 * This file implements the various methods of a singly linked list.
 *
 * Matthew Sembinelli
 * December 21, 2016
 */

#include <assert.h>
#include "linked_list.h"

#define PREVIOUS_NODE_ARRAY_INDEX ( 0 )
#define CURRENT_NODE_ARRAY_INDEX  ( 1 )

struct node
{
    int key;
    struct node* next;
};

static struct node* m_head = NULL;
static int m_size = 0;

// Private function prototypes
static struct node** get_nodes_at_index(int index);
static struct node* get_last(void);

// Public function definitions
void push_front(int key)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = key;
    new_node->next = m_head;
    m_head = new_node;
    m_size++;
}

int pop_front(void)
{
    // Assert if the list is empty. Checking if the list is empty is a precondition of the consumer.
    assert(!empty());

    int key = m_head->key;
    struct node* delete_node = m_head;
    m_head = m_head->next;
    free(delete_node);
    m_size--;
    return key;
}

void push_back(int key)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = key;
    new_node->next = NULL;

    if(empty())
    {
        m_head = new_node;
    }
    else
    {
        get_last()->next = new_node;
    }
    m_size++;
}

int pop_back(void)
{
    // Assert if the list is empty. Checking if the list is empty is a precondition of the consumer.
    assert(!empty());

    struct node** previous_and_current_nodes = get_nodes_at_index(m_size - 1);
    struct node* previous_node = previous_and_current_nodes[PREVIOUS_NODE_ARRAY_INDEX];
    struct node* current_node = previous_and_current_nodes[CURRENT_NODE_ARRAY_INDEX];

    if(m_head == current_node)
    {
        m_head = NULL;
    }
    else
    {
        previous_node->next = NULL;
    }

    int key = current_node->key;
    free(current_node);
    m_size--;
    return key;
}

int front(void)
{
    // Assert if the list is empty. Checking if the list is empty is a precondition of the consumer.
    assert(!empty());
    return m_head->key;
}

int back(void)
{
    // Assert if the list is empty. Checking if the list is empty is a precondition of the consumer.
    assert(!empty());
    return get_last()->key;
}

void insert(int index, int key)
{
    struct node* insert_node = (struct node*) malloc(sizeof(struct node));
    insert_node->key = key;

    // Insert at the very end of the list if desired index is >= list size
    if(index >= m_size)
    {
        insert_node->next = NULL;
        get_last()->next = insert_node;
    }
    // Else we are inserting at an index that already exists
    else
    {
        struct node** previous_and_current_nodes = get_nodes_at_index(index);
        struct node* previous_node = previous_and_current_nodes[PREVIOUS_NODE_ARRAY_INDEX];
        struct node* current_node = previous_and_current_nodes[CURRENT_NODE_ARRAY_INDEX];

        if(m_head == current_node)
        {
            m_head = insert_node;
            insert_node->next = current_node;
        }
        else
        {
            insert_node->next = current_node;
            previous_node->next = insert_node;
        }
    }

    m_size++;
}

void erase(int index)
{
    if(empty())
    {
        return;
    }

    struct node** previous_and_current_nodes = get_nodes_at_index(index);
    struct node* previous_node = previous_and_current_nodes[PREVIOUS_NODE_ARRAY_INDEX];
    struct node* current_node = previous_and_current_nodes[CURRENT_NODE_ARRAY_INDEX];

    if(m_head == current_node)
    {
        m_head = current_node->next;
    }
    else
    {
        previous_node->next = current_node->next;
    }

    free(current_node);
    m_size--;
}

int value_at(int index)
{
    // Assert if the list is empty. Checking if the list is empty is a precondition of the consumer.
    assert(!empty());
    return get_nodes_at_index(index)[CURRENT_NODE_ARRAY_INDEX]->key;
}

int value_n_from_end(int n)
{
    // Assert if the list is empty. Checking if the list is empty is a precondition of the consumer.
    assert(!empty());
    return get_nodes_at_index(((m_size - 1) - n))[CURRENT_NODE_ARRAY_INDEX]->key;
}

void reverse(void)
{
    if(empty())
    {
        return;
    }

    struct node* previous_node = NULL;
    struct node* current_node = m_head;
    struct node* next_node = NULL;

    while(NULL != current_node)
    {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }

    m_head = previous_node;
}

void remove_value(int key)
{
    if(empty())
    {
        return;
    }

    struct node* current_node = m_head;
    struct node* previous_node = NULL;

    while(key != current_node->key)
    {
        if(NULL == current_node)
        {
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    previous_node->next = current_node->next;
    free(current_node);
    m_size--;
}

int get_size(void)
{
    return m_size;
}

bool empty(void)
{
    return (NULL == m_head);
}

// Private function definitions
static struct node** get_nodes_at_index(int index)
{
    struct node** return_nodes = (struct node**) malloc(sizeof(struct node*));
    struct node* current_node = m_head;
    struct node* previous_node = NULL;
    for(int current_index = 0; current_index < index; current_index++)
    {
        if(NULL == current_node->next)
        {
            break;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    return_nodes[0] = previous_node;
    return_nodes[1] = current_node;
    return return_nodes;
}

static struct node* get_last(void)
{
    struct node* current_node = m_head;

    if(empty())
    {
        return m_head;
    }

    while(NULL != current_node->next)
    {
        current_node = current_node->next;
    }

    return current_node;
}


/*
 * linked_list.c
 * This file implements the various methods of a singly linked list.
 *
 * Matthew Sembinelli
 * December 21, 2016
 */

#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"

#define PREVIOUS_NODE_ARRAY_INDEX 0
#define CURRENT_NODE_ARRAY_INDEX 1

typedef struct
{
    int key;
    node* next;
} node;

static node* m_head = NULL;
static int m_size = 0;

// Private function prototypes
static node** get_nodes_at_index(int index);
static node* get_last(void);

// Public function definitions
void push_front(int key)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    new_node->next = m_head;
    m_head = new_node;
    m_size++;
}

int pop_front(void)
{
    int key = m_head->key;
    node* delete_node = m_head;
    m_head = m_head->next;
    free(delete_node);
    m_size--;
    return key;
}

void push_back(int key)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    new_node->next = NULL;
    get_last()->next = new_node;
    m_size++;
}

int pop_back(void)
{
    node* last_node = get_last();
    int key = last_node->key;
    free(last_node);
    m_size--;
    return key;
}

int front(void)
{
    return m_head->key;
}

int back(void)
{
    node* last_node = get_last();
    return last_node->key;
}

void insert(int index, int key)
{
    node* insert_node = (node*) malloc(sizeof(node));
    insert_node->key = key;
    node** previous_and_current_nodes = get_nodes_at_index(index);
    insert_node->next = previous_and_current_nodes[PREVIOUS_NODE_ARRAY_INDEX]->next;
    previous_and_current_nodes[PREVIOUS_NODE_ARRAY_INDEX]->next = insert_node;
    m_size++;
}

void erase(int index)
{
    node ** previous_and_current_nodes = get_nodes_at_index(index);
    previous_and_current_nodes[PREVIOUS_NODE_ARRAY_INDEX] = previous_and_current_nodes[CURRENT_NODE_ARRAY_INDEX]->next;
    free(previous_and_current_nodes[CURRENT_NODE_ARRAY_INDEX]);
    m_size--;
}

int value_at(int index)
{
    node ** previous_and_current_nodes = get_nodes_at_index(index);
    return previous_and_current_nodes[CURRENT_NODE_ARRAY_INDEX]->key;
}

int value_n_from_end(int n)
{
    int index = (m_size - 1) - n;
    node ** previous_and_current_nodes = get_nodes_at_index(index);
    return previous_and_current_nodes[CURRENT_NODE_ARRAY_INDEX]->key;
}

void reverse(void)
{
    for(int length = m_size; length > 0; length--)
    {
        int key = pop_back();
        push_front(key);
    }
}

void remove_value(int key)
{
    node* current_node = m_head;
    while(key != current_node->key)
    {
        if(NULL == current_node->key)
        {
            return;
        }
        current_node = current_node->next;
    }
    free(current_node);
    m_size--;
}

int size(void)
{
    return m_size;
}

bool empty(void)
{
    return (NULL == m_head);
}

// Private function definitions
static node** get_nodes_at_index(int index)
{
    node** return_nodes = (node**) malloc(sizeof(node*));
    node* current_node = m_head;
    node* previous_node = NULL;
    for(int current_index = 0; current_index <= index; current_index++)
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

static node* get_last(void)
{
    node* current_node = m_head;
    while(NULL != current_node->next)
    {
        current_node = current_node->next;
    }
    return current_node;
}


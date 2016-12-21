/*
 * linked_list.h
 * Public function prototypes for singly linked list.
 *
 * Matthew Sembinelli
 * December 21, 2016
 */

// Public function protoypes
void push_front(int key);
int pop_front(void);
void push_back(int key);
int pop_back(void);
int front(void);
int back(void);
void insert(int index, int key);
void erase(int index);
int value_at(int index);
int value_n_from_end(int n);
void reverse(void);
void remove_value(int key);
int size(void);
bool empty(void);

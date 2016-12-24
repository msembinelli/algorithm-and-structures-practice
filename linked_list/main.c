/*
 * main.c
 * This file tests the implementation of the linked list.
 *
 * Matthew Sembinelli
 * December 21, 2016
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "linked_list.h"

void print_key(int key)
{
    printf("key: %d\n", key);
    fflush(stdout);
}

void print_linked_list(void)
{
    if(empty())
    {
        printf("h -> null\n");
        return;
    }
    printf("h ");
    for(int i = 0; i < get_size(); i++)
    {
        printf("-> %d ", value_at(i));
    }
    printf("\n");
    fflush(stdout);
}

int main(void)
{
    push_back(2);
    if(!empty())
    {
        print_key(pop_back());
    }

    print_linked_list();

    push_back(3);
    if(!empty())
    {
        print_key(pop_front());
    }

    print_linked_list();

    push_back(11);
    push_back(10);

    print_linked_list();

    push_front(5);
    push_front(22);
    push_front(100);

    print_linked_list();

    print_key(value_at(2));
    print_key(front());
    print_key(back());

    if(!empty())
    {
        erase(0);
    }

    print_linked_list();

    if(!empty())
    {
        erase(-1);
    }

    print_linked_list();

    if(!empty())
    {
        erase(100);
    }

    print_linked_list();

    insert(0, 99);

    print_linked_list();

    insert(100, 555);
    print_linked_list();

    insert(2, 111);

    print_linked_list();

    if(!empty())
    {
        erase(2);
    }

    print_linked_list();

    print_key(value_at(100));
    print_key(value_at(-1));
    print_key(value_n_from_end(100));
    print_key(value_n_from_end(1));
    print_key(value_n_from_end(-1));
    insert(100, 555);

    print_linked_list();

    if(!empty())
    {
        remove_value(555);
    }

    print_linked_list();

    if(!empty())
    {
        remove_value(555);
    }

    print_linked_list();

    push_front(88);
    push_front(77);
    push_front(66);

    print_linked_list();

    reverse();

    print_linked_list();

    return 0;
}

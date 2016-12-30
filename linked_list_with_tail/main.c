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
#include "linked_list_with_tail.h"

void print_key(int key)
{
    printf("key: %d\n", key);
    fflush(stdout);
}

void print_linked_list(linked_list* list)
{
    if(empty(list))
    {
        printf("h -> null\n");
        return;
    }
    printf("h ");
    for(int i = 0; i < get_size(list); i++)
    {
        printf("-> %d ", value_at(list, i));
    }
    printf("\n");
    fflush(stdout);
}

int main(void)
{
    linked_list* list = init();
    push_back(list, 2);
    if(!empty(list))
    {
        print_key(pop_back(list));
    }

    print_linked_list(list);

    push_back(list, 3);
    if(!empty(list))
    {
        print_key(pop_front(list));
    }

    print_linked_list(list);

    push_back(list, 11);
    push_back(list, 10);

    print_linked_list(list);

    push_front(list, 5);
    push_front(list, 22);
    push_front(list, 100);

    print_linked_list(list);

    print_key(value_at(list, 2));
    print_key(front(list));
    print_key(back(list));

    if(!empty(list))
    {
        erase(list, 0);
        erase(list, 0);
        erase(list, 0);
    }

    print_linked_list(list);

    if(!empty(list))
    {
        erase(list, -1);
    }

    print_linked_list(list);

    if(!empty(list))
    {
        erase(list, 100);
    }

    print_linked_list(list);

    insert(list, 0, 99);

    print_linked_list(list);

    insert(list, 100, 555);
    print_linked_list(list);

    insert(list, 2, 111);

    print_linked_list(list);

    if(!empty(list))
    {
        erase(list, 2);
    }

    print_linked_list(list);

    print_key(value_at(list, 100));
    print_key(value_at(list, -1));
    print_key(value_n_from_end(list, 100));
    print_key(value_n_from_end(list, 1));
    print_key(value_n_from_end(list, -1));
    insert(list, 100, 555);

    print_linked_list(list);

    if(!empty(list))
    {
        remove_value(list, 555);
    }

    print_linked_list(list);

    if(!empty(list))
    {
        remove_value(list, 555);
    }

    print_linked_list(list);

    if(!empty(list))
    {
        remove_value(list, 99);
    }

    print_linked_list(list);

    push_front(list, 88);
    push_front(list, 77);
    push_front(list, 66);

    print_linked_list(list);

    reverse(list);

    print_linked_list(list);

    if(!empty(list))
    {
        erase(list, 2);
    }

    print_linked_list(list);

    destroy(list);

    return 0;
}

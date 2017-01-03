/*****************************************************************************
 * main.c
 * This file tests the implementation of the binary search tree.
 *
 * Matthew Sembinelli
 * January 2, 2017
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "binary_search_tree.h"

/*****************************************************************************
 *                                Definitions                                *
 *****************************************************************************/
int main(void)
{
    binary_search_tree* bst = bst_init();

    bst_insert_node(bst, 5);
    bst_insert_node(bst, 3);
    bst_insert_node(bst, 1);
    bst_insert_node(bst, 0);
    bst_insert_node(bst, 2);
    bst_insert_node(bst, 4);
    bst_insert_node(bst, 6);
    bst_print_values(bst);

    printf("NODE COUNT: %d\n", bst_node_count(bst));
    printf("DEPTH: %d\n", bst_get_height(bst));
    printf("MAX: %d\n", bst_get_max(bst));
    printf("MIN: %d\n", bst_get_min(bst));
    if(bst_node_exists(bst, 0))
    {
        printf("NODE 0 EXISTS\n");
    }
    else
    {
        printf("NODE 0 DNE\n");
    }

    if(bst_valid(bst))
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

    bst_delete_node(bst, 3);
    bst_delete_node(bst, 6);
    bst_print_values(bst);

    bst_delete_node(bst, 1);
    bst_delete_node(bst, 5);
    bst_print_values(bst);

    bst_delete_node(bst, 4);
    bst_delete_node(bst, 0);
    bst_delete_node(bst, 2);
    bst_print_values(bst);

    bst_destroy(bst);
    return 0;
}

/*****************************************************************************
 * main.c
 * This file tests the implementation of an array based hash table.
 *
 * Matthew Sembinelli
 * January 1, 2017
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "hash_table.h"

/*****************************************************************************
 *                                Definitions                                *
 *****************************************************************************/
int main(void)
{
    hash_table* table = ht_init(8);

    ht_add(table, 1, 1);
    ht_add(table, 2, 222);
    ht_add(table, 3, 333);
    ht_add(table, 4, 444);

    if(ht_exists(table, 4))
    {
        printf("EXISTS\n");
    }
    else
    {
        printf("DOES NOT EXIST\n");
    }

    if(ht_exists(table, 5))
    {
        printf("EXISTS\n");
    }
    else
    {
        printf("DOES NOT EXIST\n");
    }
    fflush(stdout);

    printf("ht_get: %d", ht_get(table, 1));
    printf(" %d", ht_get(table, 2));
    printf(" %d", ht_get(table, 3));
    printf(" %d\n", ht_get(table, 4));
    fflush(stdout);

    ht_remove(table, 1);
    ht_remove(table, 2);
    ht_add(table, 5, 555);
    ht_add(table, 6, 666);

    printf("ht_get: %d", ht_get(table, 3));
    printf(" %d", ht_get(table, 4));
    printf(" %d", ht_get(table, 5));
    printf(" %d\n", ht_get(table, 6));
    fflush(stdout);

    ht_add(table, 6, 111);

    printf("ht_get: %d", ht_get(table, 3));
    printf(" %d", ht_get(table, 4));
    printf(" %d", ht_get(table, 5));
    printf(" %d\n", ht_get(table, 6));
    fflush(stdout);

    ht_remove(table, 3);
    ht_remove(table, 4);
    ht_remove(table, 5);
    ht_remove(table, 6);

    ht_destroy(table);

    return 0;
}

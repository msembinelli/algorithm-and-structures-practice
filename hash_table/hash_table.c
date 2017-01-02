/*****************************************************************************
 * hash_table.c
 * This file implements the various methods of an array based hash_table.
 *
 * Matthew Sembinelli
 * January 1, 2017
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <assert.h>
#include <time.h>
#include <string.h>
#include "hash_table.h"

/*****************************************************************************
 *                                  Types                                    *
 *****************************************************************************/
typedef struct
{
    int key;
    int value;
} hash_table_item;

// Private queue structure
typedef struct
{
    hash_table_item** array;
    int a;
    int b;
    int prime;
    int size;
} hash_table_private;

/*****************************************************************************
 *                             Private Prototypes                            *
 *****************************************************************************/
static int hash(hash_table_private* table_private, int key);
static int generate_prime_greater_than(int number);

/*****************************************************************************
 *                             Public Definitions                            *
 *****************************************************************************/
hash_table* ht_init(int size)
{
    // Must be > 0 and power of two to use fast wrap around property
    assert(size > 0 && ((size & (size - 1)) == 0));

    hash_table* table = (hash_table*) malloc(sizeof(hash_table));
    assert(table); // Check if malloc was successful

    hash_table_private* table_private = (hash_table_private*) malloc(sizeof(hash_table_private));
    assert(table_private); // Check if malloc was successful

    table_private->array = (hash_table_item**) malloc(sizeof(hash_table_item*) * size);
    assert(table_private->array); // Check if malloc was successful
    memset(table_private->array, 0, sizeof(hash_table_item*) * size);

    table_private->size = size;

    // Generate a and b coefficients for hashing function
    srand(time(NULL));
    table_private->a = rand();
    table_private->b = rand();

    // Generate prime number >= table size
    table_private->prime = generate_prime_greater_than(size);

    table->private = table_private;
    return table;
}

void ht_add(hash_table* table, int key, int value)
{
    // Null check table
    assert(table && table->private);

    hash_table_private* table_private = table->private;
    int start_index = hash(table_private, key);
    int index = start_index;

    while(table_private->array[index] != NULL && table_private->array[index]->key != key)
    {
        // Increase index w/ power of two wraparound
        index = (index + 1) & (table_private->size - 1);
        assert(index != start_index); // Check if table is full
    }
    if(table_private->array[index] == NULL)
    {
        // No item ht_exists yet with that key, create one
        hash_table_item* item = (hash_table_item*) malloc(sizeof(hash_table_item));
        item->key = key;
        item->value = value;
        table_private->array[index] = item;
    }
    else
    {
        // Item already ht_exists, update the value
        table_private->array[index]->value = value;
    }
}

int ht_get(hash_table* table, int key)
{
    // Null check table
    assert(table && table->private);

    hash_table_private* table_private = table->private;
    int index = hash(table_private, key);

    // Existence check, this is a precondition for calling get()
    assert(ht_exists(table, key));

    while(true)
    {
        if(table_private->array[index] != NULL)
        {
            if(table_private->array[index]->key == key)
            {
                break;
            }
        }
        // Increase index w/ power of two wraparound
        index = (index + 1) & (table_private->size - 1);
    }

    return table_private->array[index]->value;
}

void ht_remove(hash_table* table, int key)
{
    // Null check table
    assert(table && table->private);

    hash_table_private* table_private = table->private;
    int index = hash(table_private, key);

    // Existence check, this is a precondition for calling remove()
    assert(ht_exists(table, key));

    while(true)
    {
        if(table_private->array[index] != NULL)
        {
            if(table_private->array[index]->key == key)
            {
                break;
            }
        }
        // Increase index w/ power of two wraparound
        index = (index + 1) & (table_private->size - 1);
    }

    free(table_private->array[index]);
    table_private->array[index] = NULL;
}

bool ht_exists(hash_table* table, int key)
{
    // Null check table
    assert(table && table->private);

    hash_table_private* table_private = table->private;
    int index = hash(table_private, key);
    int start_index = index;

    while(true)
    {
        if(table_private->array[index] != NULL)
        {
            if(table_private->array[index]->key == key)
            {
                return true;
            }
        }
        // Increase index w/ power of two wraparound
        index = (index + 1) & (table_private->size - 1);

        // We have wrapped around to the beginning and haven't found it
        if(start_index == index)
        {
            break;
        }
    }
    return false;
}

void ht_destroy(hash_table* table)
{
    // Null check
    assert(table && table->private);

    hash_table_private* table_private = table->private;
    free(table_private->array);
    table_private->array = NULL;
    free(table->private);
    table->private = NULL;
    free(table);
    table = NULL;
}

/*****************************************************************************
 *                            Private Definitions                            *
 *****************************************************************************/
static int hash(hash_table_private* table_private, int key)
{
    // Null check table
    assert(table_private);
    return((table_private->a*key + table_private->b) % table_private->prime) % table_private->size;
}

static int generate_prime_greater_than(int number)
{
    bool is_prime = true;
    int test_number = number + 1;

    // iterates range from the upper bound going down until range is equal to 2
    while(true)
    {
        // Immediately eliminate even numbers
        if(test_number % 2 != 0)
        {
            for(int p = 2; p * p <= test_number; p++)
            {
                if(test_number % p == 0)
                {
                    is_prime = false;
                    break;
                }
            }
            // If loop completes and flag is still true we have a prime
            if(is_prime)
            {
                break;
            }
        }
        // Reset prime flag, next number
        is_prime = true;
        test_number++;
    }
    return test_number;
}




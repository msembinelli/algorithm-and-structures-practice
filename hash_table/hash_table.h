/*****************************************************************************
 * hash_table.h
 * Public function prototypes for array based hash_table.
 *
 * Matthew Sembinelli
 * January 1, 2017
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <stdlib.h>
#include <stdbool.h>

/*****************************************************************************
 *                                  Types                                    *
 *****************************************************************************/
// Public queue structure
typedef struct
{
    void* private;
} hash_table;

/*****************************************************************************
 *                             Public Prototypes                             *
 *****************************************************************************/
hash_table* ht_init(int size);
void ht_add(hash_table* table, int key, int value);
void ht_remove(hash_table* table, int key);
int ht_get(hash_table* table, int key);
bool ht_exists(hash_table* table, int key);
void ht_destroy(hash_table* table);

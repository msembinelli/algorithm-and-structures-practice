/*****************************************************************************
 * binary_search_tree.h
 * Public function prototypes for a binary search tree.
 *
 * Matthew Sembinelli
 * January 2, 2017
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <stdlib.h>
#include <stdbool.h>

/*****************************************************************************
 *                                  Types                                    *
 *****************************************************************************/
// Public binary search tree structure
typedef struct
{
    void* private;
} binary_search_tree;

/*****************************************************************************
 *                             Public Prototypes                             *
 *****************************************************************************/
binary_search_tree* bst_init(void);
void bst_destroy(binary_search_tree* bst);
void bst_insert_node(binary_search_tree* bst, int data);
void bst_delete_node(binary_search_tree* bst, int data);
void bst_print_values(binary_search_tree* bst);
void bst_print_values_in_range(binary_search_tree* bst, int lo, int hi); //range inclusive
int bst_node_count(binary_search_tree* bst);
int bst_get_height(binary_search_tree* bst);
int bst_get_min(binary_search_tree* bst);
int bst_get_max(binary_search_tree* bst);
bool bst_node_exists(binary_search_tree* bst, int data);
bool bst_valid(binary_search_tree* bst);


/*****************************************************************************
 * binary_search_tree.c
 * This file implements the various methods of a binary search tree.
 *
 * Matthew Sembinelli
 * January 2, 2017
 *****************************************************************************/

/*****************************************************************************
 *                                 Includes                                  *
 *****************************************************************************/
#include <assert.h>
#include <stdio.h>
#include "binary_search_tree.h"

/*****************************************************************************
 *                                  Types                                    *
 *****************************************************************************/
// Forward declaration of node
typedef struct node node;

// Private node structure representation for a bst node element
struct node
{
    int data;
    node* left;
    node* right;
};

// Private bst structure
typedef struct
{
    node* root;
    int number_of_nodes;
} binary_search_tree_private;

/*****************************************************************************
 *                             Private Prototypes                            *
 *****************************************************************************/
static void delete_tree_recursive(node** root);
static void insert_node_recursive(node** root, int data);
static void delete_node_recursive(node** parent_ptr,
        node** root_ptr, int data);
static void print_tree_recursive(node* root);
static int get_height_recursive(node* root, int height);
static bool node_exists_recursive(node* root, int data);
static bool tree_valid_recursive(node* root);
static node* create_node(int data);
static int get_min(node* root);
static int get_max(node* root);

/*****************************************************************************
 *                             Public Definitions                            *
 *****************************************************************************/
binary_search_tree* bst_init(void)
{
    binary_search_tree_private* bst_p = (binary_search_tree_private*)
        malloc(sizeof(binary_search_tree_private));
    // Check if malloc passed
    assert(bst_p);

    // Starting state is the BST points to nothing
    bst_p->root = NULL;
    bst_p->number_of_nodes = 0;

    binary_search_tree* bst = (binary_search_tree*)
        malloc(sizeof(binary_search_tree));
    // Check if malloc passed
    assert(bst);

    bst->private = bst_p;

    return bst;
}

void bst_destroy(binary_search_tree* bst)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    // Delete tree recursively
    delete_tree_recursive(&bst_p->root);

    free(bst_p);
    bst_p = NULL;
}

void bst_insert_node(binary_search_tree* bst, int data)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    insert_node_recursive(&bst_p->root, data);
    bst_p->number_of_nodes++;
}

void bst_delete_node(binary_search_tree* bst, int data)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    delete_node_recursive(NULL, &bst_p->root, data);
    bst_p->number_of_nodes--;
}

void bst_print_values(binary_search_tree* bst)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    printf("PRINT TREE\n");
    if(NULL == bst_p->root)
    {
        printf("EMPTY\n");
        return;
    }

    print_tree_recursive(bst_p->root);
}

int bst_node_count(binary_search_tree* bst)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    return bst_p->number_of_nodes;
}

int bst_get_height(binary_search_tree* bst)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    return get_height_recursive(bst_p->root, 0);
}

int bst_get_min(binary_search_tree* bst)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    return get_min(bst_p->root);
}
int bst_get_max(binary_search_tree* bst)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    return get_max(bst_p->root);

}

bool bst_node_exists(binary_search_tree* bst, int data)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    return node_exists_recursive(bst_p->root, data);
}

bool bst_valid(binary_search_tree* bst)
{
    assert(bst);
    binary_search_tree_private* bst_p = bst->private;

    return tree_valid_recursive(bst_p->root);
}

/*****************************************************************************
 *                            Private Definitions                            *
 *****************************************************************************/static void delete_tree_recursive(node** root_ptr)
{
    if(NULL == *root_ptr)
    {
        return;
    }

    node* root = *root_ptr;

    delete_tree_recursive(&root->left);
    delete_tree_recursive(&root->right);

    *root_ptr = NULL;
    free(root);
    root = NULL;
}

static void insert_node_recursive(node** root_ptr, int data)
{
    if(NULL == *root_ptr)
    {
        // We are at top of tree
        *root_ptr = create_node(data);
        return;
    }

    node* root = *root_ptr;

    // If someone tries to insert duplicate, blow up
    assert(data != root->data);

    if(data > root->data)
    {
        if(NULL == root->right)
        {
            // We can put the data here
            root->right = create_node(data);
        }
        else
        {
            insert_node_recursive(&root->right, data);
        }
    }
    else
    {
        if(NULL == root->left)
        {
            // We can put the data here
            root->left = create_node(data);
        }
        else
        {
            insert_node_recursive(&root->left, data);
        }
    }
}

static node* create_node(int data)
{
    node* new = (node*) malloc(sizeof(node));
    new->data = data;
    new->right = NULL;
    new->left = NULL;
    return new;
}

static void delete_node_recursive(node** parent_ptr,
        node** root_ptr, int data)
{
    if(NULL == *root_ptr)
    {
        // Not found
        return;
    }

    node* root = *root_ptr;
    node* parent = NULL;
    if(NULL != parent_ptr)
    {
       parent = *parent_ptr;
    }


    if(data == root->data)
    {
        // No children case
        if(NULL == root->left && NULL == root->right)
        {
            if(NULL != parent)
            {
                if(parent->right == root)
                {
                    parent->right = NULL;
                }
                else
                {
                    parent->left = NULL;
                }
                free(root);
                root = NULL;
            }
            // We are dealing with the top level root node so set NULL
            else
            {
                *root_ptr = NULL;
            }
        }
        // Two children
        else if(NULL != root->left && NULL != root->right)
        {
            if(data > parent->data)
            {
                // Replace current data with minimum in right subtree
                root->data = get_min(root->right);
                delete_node_recursive(&root, &root->right, root->data);
            }
            else
            {
                // Replace current data with maximum in left subtree
                root->data = get_max(root->left);
                delete_node_recursive(&root, &root->left, root->data);
            }
        }
        // One child
        else
        {
            node* selected_parent_child = NULL;
            if(NULL == root->left && NULL != root->right)
            {
                selected_parent_child = root->right;
            }
            else
            {
                selected_parent_child = root->left;
            }

            if(NULL != parent)
            {
                if(data > parent->data)
                {
                    parent->right = selected_parent_child;
                }
                else
                {
                    parent->left = selected_parent_child;
                }

                free(root);
                root = NULL;
            }
            // We are dealing with the top level root node
            else
            {
                *root_ptr = selected_parent_child;
            }
        }
    }
    else if(data > root->data)
    {
        delete_node_recursive(&root, &root->right, data);
    }
    else
    {
        delete_node_recursive(&root, &root->left, data);
    }
}

static void print_tree_recursive(node* root)
{
    if(NULL == root)
    {
        return;
    }

    print_tree_recursive(root->left);
    printf("%d\n", root->data);
    fflush(stdout);
    print_tree_recursive(root->right);
}

static int get_height_recursive(node* root, int height)
{
    int height_left = 0;
    int height_right = 0;

    if(NULL != root->left || NULL != root->right)
    {
        height++;
        if(NULL != root->left)
        {
            height_left = get_height_recursive(root->left, height);
        }
        if(NULL != root->right)
        {
            height_right = get_height_recursive(root->right, height);
        }
    }
    else
    {
        // We are at the bottom of the tree
        return height;
    }

    if(height_right == height_left)
    {
        return height_right;
    }
    else if(height_right > height_left)
    {
        return height_right;
    }
    else
    {
        return height_left;
    }
}

static bool node_exists_recursive(node* root, int data)
{
    if(NULL == root)
    {
        return false;
    }

    if(data == root->data)
    {
        return true;
    }
    else if(data > root->data)
    {
        return node_exists_recursive(root->right, data);
    }
    else
    {
        return node_exists_recursive(root->left, data);
    }
}

static bool tree_valid_recursive(node* root)
{
    if(NULL == root)
    {
        return true;
    }

    if(NULL != root->left)
    {
        if(root->left->data > root->data)
        {
            return false;
        }
    }
    if(NULL != root->right)
    {
        if(root->right->data < root->data)
        {
            return false;
        }
    }

    return tree_valid_recursive(root->right) &&
        tree_valid_recursive(root->left);
}

static int get_min(node* root)
{
    while(NULL != root->left)
    {
        root = root->left;
    }

    return root->data;
}

static int get_max(node* root)
{
    while(NULL != root->right)
    {
        root = root->right;
    }

    return root->data;
}

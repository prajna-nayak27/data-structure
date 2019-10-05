#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include <stdint.h>
typedef struct _tree_node_ TreeNode;
typedef struct _bst_ BST;
struct _tree_node_{
	int32_t data;
	TreeNode *left;
	TreeNode *right;
};
struct _bst_
{
	TreeNode *node;
	uint32_t mass;
};

BST bst_new();
uint32_t bst_count(BST *tree);
BST* bst_add_node(BST *tree,int32_t ele);
BST* bst_delete_node(BST *tree,int32_t ele);
uint32_t bst_lookup(BST *tree,int32_t key);
BST* bst_in_order(BST *tree);
BST* pre_order(BST *tree);
BST* post_oder(BST *tree);
BST* level_inoder(BST *tree);
uint32_t bst_height(BST *tree);

#end_if

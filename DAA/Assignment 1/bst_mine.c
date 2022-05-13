// Name:Ghanashyam Mahesh Bhat
// SRN: PES1UG20CS153
#include "bst.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
*/

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
	bst->root = NULL;
}


// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
static node_t* create_node(int key)
{
	node_t* temp  =(node_t*)malloc(sizeof(node_t));
	temp -> key = key;
	temp -> left = NULL;
	temp ->right = NULL;
	return temp;
}

static node_t* insert_node(node_t* tree,int key,int* count_ptr)
{
	if(tree==NULL)
	{
		tree = create_node(key);*count_ptr+=1;
		return tree;
	}
	else if(key<tree->key)
	{
		*count_ptr+=1;
		tree->left=insert_node(tree->left,key,count_ptr);
	}
	else if(key>tree->key)
	{
		*count_ptr+=1;
		tree->right=insert_node(tree->right,key,count_ptr);
	}
	
	return tree;
}

void insert(bst_t *tree, int key, int *count_ptr)
{
	if(tree->root==NULL)
		tree->root = create_node(key);
	else
		tree->root = insert_node(tree->root,key,count_ptr);
}



// Delete key from the BST
// Replaces node with in-order successor
static node_t* in_suc(node_t* node,node_t* prev,int* count_ptr)
{
	if (node->left==NULL)
	{
		*count_ptr+=1;
		return node;
	}
	else
	{
		*count_ptr+=1;
		prev = node;*count_ptr+=1;
		return in_suc(node->left,prev,count_ptr);
	}
}

static node_t* delete(node_t* node,int key,int* count_ptr)
{
	if(node->key == key)
	{
		if(node->right ==NULL)
		{	
			*count_ptr+=1;
			node_t* temp = node->left;
			free(node);
			return temp;
		}
		else if(node->left ==NULL)
		{	
			*count_ptr+=1;
			node_t* temp = node->right;
			free(node);
			return temp;
		}
		else
		{
			*count_ptr+=1;
			node_t* prev = NULL;
			node_t* suc = in_suc(node->right,prev,count_ptr);
			int temp = node->key;
			node->key = suc->key;
			suc->key = temp;
			if (prev !=NULL)
				prev->left =  delete(suc,key,count_ptr);
			else 
				node->right = delete(suc,key,count_ptr);
		}
		
	}
	else if(key<node->key)
	{
		*count_ptr+=1;
		node->left = delete(node->left,key,count_ptr);
	}
	else if(key>node->key)
	{
		*count_ptr+=1;
		node->right = delete(node->right,key,count_ptr);
	}
}

void delete_element(bst_t *tree, int key, int *count_ptr)
{
	delete(tree->root,key,count_ptr);
}

// Searches for the element key in the bst
// Returns the element if found, else -1
static int search_key(node_t* node,int key,int *count_ptr)
{
	if (node==NULL)
	{
		*count_ptr+=1;
		return -1;
	}
	else if(node->key ==key)
	{
		*count_ptr+=1;
		return key;
	}
	else if(node->key < key)
	{
		*count_ptr+=1;
		return search_key(node->left,key,count_ptr);
	}
	else 
	{
		*count_ptr+=1;
		return search_key(node->right,key,count_ptr);
	}
	
}

int search(const bst_t *tree, int key, int *count_ptr)
{
	if(tree->root ==NULL)
	{
		*count_ptr+=1;
		return -1;
	}
	else 
	{
		*count_ptr+=1;
		return search_key(tree->root,key,count_ptr);
	}
}

// Returns the maximum element in the BST
static int max_ele(node_t* node,int* count_ptr)
{
	if(node->right==NULL)
	{
		*count_ptr+=1;
		return node->key;
	}
	else
	{
		*count_ptr+=1;
		return max_ele(node->right,count_ptr);
	}
}

int find_max(const bst_t *tree, int *count_ptr)
{
	if(tree->root  ==NULL)
	{
		*count_ptr+=1;
		return -1;
	}
	else 
	{
		*count_ptr+=1;
		return max_ele(tree->root,count_ptr);
	}
}

// Deletes all the elements of the bst
static void post_del(node_t* node)
{
	if(node==NULL)
	{
		return;
	}
	else
	{
		post_del(node->left);
		post_del(node->right);
		free(node);
	}
}

void free_bst(bst_t *bst) 
{
	post_del(bst->root);
	free(bst);
	bst=NULL;
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
	post_del(bst->root);
	bst->root = NULL;
}

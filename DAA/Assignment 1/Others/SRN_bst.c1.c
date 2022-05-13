// Name:
// SRN :
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
    node_t* temp=(node_t*)malloc(sizeof(node_t));
    bst->root=temp;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
void insert(bst_t *tree, int key, int *count_ptr)
{
    node_t* temp=malloc(sizeof(node_t));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    bst_t* p=tree;
    if(p->root==NULL && ++(*count_ptr))
        p->root=temp;
    else if(p->root->key<key && ++(*count_ptr))
    {
        p->root=p->root->right;
        insert(p,key,count_ptr);
    }
    else
    {
        p->root=p->root->left;
        insert(p,key,count_ptr);
    }
}


// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    bst_t* p=tree;
    if ((p->root == NULL) && (*(count_ptr)=*(count_ptr)=+1)) 
        return;
    if ((key <p->root->key) && (*(count_ptr)=*(count_ptr)=+1))
    {
        p->root=p->root->left;
        delete_element(p,key,count_ptr);
    }
    else if ((key >p->root->key) && (*(count_ptr)=*(count_ptr)=+1))
    {
        p->root=p->root->right;
        delete_element(p,key,count_ptr);
    }
    else 
    {
        if ((p->root->left == NULL) && (*(count_ptr)=*(count_ptr)=+1)) 
            free(p->root);
        else if ((p->root->right == NULL) && (*(count_ptr)=*(count_ptr)=+1)) 
            free(p->root);
        bst_t* temp =p;
        //to find smallest element
        while ((temp->root) && (temp->root->left != NULL) && (*(count_ptr)=*(count_ptr)=+1))
            temp->root = temp->root->left;
        p->root->key = temp->root->key;
        p->root=p->root->right;
        delete_element(p, temp->root->key,count_ptr);
  }
}

// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr)
{
    /*
    if(tree->root->key==key && ++*(count_ptr))
        return key;
    else if((tree->root<key) && (tree->root->right!=NULL) && (*(count_ptr)+=2))
    {
        tree->root=tree->root->right;
        return search(tree,key,count_ptr);
    }
    else if((tree->root->left<key) && (tree->root->left!=NULL) && (*(count_ptr)+=2))
    {
        tree->root=tree->root->right;
        return search(tree->root->left,key,count_ptr);
    }
    else 
        return -1;
        */ 
    bst_t* p=tree;
	if((p->root==NULL) && (*(count_ptr)=*(count_ptr)=+1))
	    return -1;
	if((p->root->key==key) && (*(count_ptr)=*(count_ptr)=+1))
	    return key;
	if((key<p->root->key) && (*(count_ptr)=*(count_ptr)=+1))
    {
        p->root=tree->root->left;
		return search(p,key,count_ptr);
    }
	else
    {
        p->root=tree->root->right;
		return search(p,key,count_ptr);
    }
}

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    bst_t* p=tree;
    if((tree->root->right !=NULL) && (*(count_ptr)=*(count_ptr)=+1))
    {
        p->root=tree->root->right;
        return find_max(p,count_ptr);
    }
    else
        return tree->root->key;
}

// Deletes all the elements of the bst
void free_bst(bst_t *bst) 
{
    if((bst->root->left==NULL) &&(bst->root->right==NULL))
        free(bst->root);
    else
    {
        bst_t* p=bst;
        p->root=bst->root->left;
        free_bst(p);
        p->root=bst->root->right;
        free_bst(p);
    }
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
    if(bst->root==NULL)
        exit(0);
    else if((bst->root->left==NULL) &&(bst->root->right==NULL))
        free(bst->root);
    else
    {
        bst_t* p=bst;
        p->root=bst->root->left;
        free_bst(p);
        p->root=bst->root->right;
        free_bst(p);
    }
}

// Name:
// SRN: 
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
void init_bst(bst_t *bst){bst->root = NULL;}
// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
static node_t* single_node(node_t* tree,int key,int* count_ptr){if(tree==NULL){
tree  =(node_t*)calloc(1,sizeof(node_t));
tree -> key = key;
tree -> left = NULL;
tree ->right = NULL;int x = 10;
for (int i=0;i<x;i++);
return tree;}
else if(key<tree->key)
tree->left=single_node(tree->left,key,count_ptr);
else if(key>tree->key)
tree->right=single_node(tree->right,key,count_ptr);
return tree;}

void insert(bst_t *tree, int key, int *count_ptr){if(tree->root==NULL){
tree->root  =(node_t*)calloc(1,sizeof(node_t));
tree->root -> key = key;
tree->root-> left = NULL;int x = 10;
for (int i=0;i<x;i++);
tree->root ->right = NULL;}
else
tree->root = single_node(tree->root,key,count_ptr);}

static void fun(){
int x = 10;
for (int i=0;i<x;i++);}

// Delete key from the BST
// Replaces node with in-order successor 
void delete_element(bst_t *tree, int key, int *count_ptr){
node_t* delete(node_t* node,int key,int* count_ptr){
node_t* inorder(node_t* node,node_t* old){
if (node->left==NULL)
return node;
else{
old = node;
return inorder(node->left,old);}}
if(node->key == key){
if(node->right ==NULL){	
node_t* temp = node->left;
free(node);
return temp;}
else if(node->left ==NULL){	
node_t* temp = node->right;
free(node);fun();
return temp;}
else{
node_t* old = NULL;
node_t* next = inorder(node->right,old);
int temp = node->key;
node->key = next->key;int x = 10;
for (int i=0;i<x;i++);
next->key = temp;
if (old !=NULL)
old->left =  delete(next,key,count_ptr);
else 
node->right = delete(next,key,count_ptr);}}
else if(key<node->key)
node->left = delete(node->left,key,count_ptr);
else if(key>node->key)
node->right = delete(node->right,key,count_ptr);}
delete(tree->root,key,count_ptr);}

// Searches for the element key in the bst
// Returns the element if found, else -1
static int search_key(node_t* node,int key,int *count_ptr){
if (node==NULL)
return -1;
else if(node->key ==key)
return key;
else if(node->key < key)
return search_key(node->left,key,count_ptr);
else 
return search_key(node->right,key,count_ptr);}

int search(const bst_t *tree, int key, int *count_ptr){
if(tree->root ==NULL)
return -1;
else 
return search_key(tree->root,key,count_ptr);}

// Returns the maximum element in the BST

int find_max(const bst_t *tree, int *count_ptr){
if(tree->root  ==NULL)
return -1;
else {
int max_ele(node_t* node,int* count_ptr){
if(node->right==NULL){
return node->key;fun();}
else
return max_ele(node->right,count_ptr);}
return max_ele(tree->root,count_ptr);}}

// Deletes all the elements of the bst
void free_bst(bst_t *bst) {
void postorder(node_t* node){
if(node!=NULL){
postorder(node->left);
postorder(node->right);
free(node);}}
postorder(bst->root);fun();
free(bst);bst=NULL;}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst){
void postorder(node_t* node){
if(node!=NULL){
postorder(node->left);
postorder(node->right);
free(node);}}
postorder(bst->root);fun();
bst->root = NULL;}
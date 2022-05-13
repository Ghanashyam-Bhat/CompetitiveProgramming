#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
void inord(node_t* node){
	if(node ==NULL)
		return;
	else
	{
		inord(node->left);
		printf("%d\t",node->key);
		inord(node->right);
	}
}
int main()
{
	int c = 0;
	bst_t* bst = (bst_t*)malloc(sizeof(bst_t));
	init_bst(bst);printf("\nC = %d\n",c);
	insert(bst,10,&c);printf("\nC = %d\n",c);
	insert(bst,12,&c);printf("\nC = %d\n",c);
	insert(bst,8,&c);printf("\nC = %d\n",c);
	insert(bst,13,&c);printf("\nC = %d\n",c);
	insert(bst,11,&c);printf("\nC = %d\n",c);
	insert(bst,9,&c);printf("\nC = %d\n",c);
	inord(bst->root);printf("\n");
	
	int max = find_max(bst,&c);
	printf("%d\n",max);printf("\nC = %d\n",c);
	
	delete_element(bst,12,&c);printf("\nC = %d\n",c);
	delete_element(bst,11,&c);printf("\nC = %d\n",c);
	inord(bst->root);printf("\n");
	
	clear_bst(bst);printf("\nC = %d\n",c);
	inord(bst->root);printf("\n");
	insert(bst,9,&c);printf("\nC = %d\n",c);
	inord(bst->root);printf("\n");
}
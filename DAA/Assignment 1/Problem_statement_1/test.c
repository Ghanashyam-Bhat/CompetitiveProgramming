#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
	heap_t heap;int c=0;
	printf("\nC = %d\n",c);
	init_heap(&heap,6);printf("\nC = %d\n",c);
	insert(&heap,8,&c);printf("\nC = %d\n",c);
	insert(&heap,10,&c);printf("\nC = %d\n",c);
	insert(&heap,12,&c);printf("\nC = %d\n",c);
	insert(&heap,5,&c);printf("\nC = %d\n",c);
	insert(&heap,6,&c);printf("\nC = %d\n",c);
	insert(&heap,15,&c);printf("\nC = %d\n",c);
	for(int i=0;i<heap.size;i++)
		printf("%d\t",heap.arr[i]);
	printf("\n");
	
	printf("%d\n",extract_max(&heap,&c));printf("\nC = %d\n",c);
	for(int i=0;i<heap.size;i++)
		printf("%d\t",heap.arr[i]);
	printf("\n");
	
	printf("%d\n",search(&heap,2,&c));printf("\nC = %d\n",c);
	printf("%d\n",search(&heap,6,&c));printf("\nC = %d\n",c);
	
	printf("%d\n",find_max(&heap,&c));printf("\nC = %d\n",c);
	printf("%d\n",find_min(&heap,&c));printf("\nC = %d\n",c);
	
	clear_heap(&heap);printf("\nC = %d\n",c);
	for(int i=0;i<heap.size;i++)
		printf("%d\t",heap.arr[i]);
	printf("\n");
}
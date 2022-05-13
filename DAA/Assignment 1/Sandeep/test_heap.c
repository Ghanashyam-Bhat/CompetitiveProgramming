#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
	heap_t heap;int c=0;
	init_heap(&heap,6);
	insert(&heap,8,&c);
	insert(&heap,10,&c);
	insert(&heap,12,&c);
	insert(&heap,5,&c);
	insert(&heap,6,&c);
	insert(&heap,15,&c);
	for(int i=0;i<heap.size;i++)
		printf("%d\t",heap.arr[i]);
	printf("\n");
	
	printf("%d\n",extract_max(&heap,&c));
	for(int i=0;i<heap.size;i++)
		printf("%d\t",heap.arr[i]);
	printf("\n");
	
	printf("%d\n",search(&heap,2,&c));
	printf("%d\n",search(&heap,6,&c));
	
	printf("%d\n",find_max(&heap,&c));
	printf("%d\n",find_min(&heap,&c));
	
	clear_heap(&heap);
	for(int i=0;i<heap.size;i++)
		printf("%d\t",heap.arr[i]);
	printf("\n");
	printf("Haleluya");
}
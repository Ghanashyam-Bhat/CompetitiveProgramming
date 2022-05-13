// Name:Ghanashyam Mahesh Bhat
// SRN: PES1UG20CS153
#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size)
{
	//heap = (heap_t*)malloc(sizeof(heap_t));
	heap->arr = (int*)malloc(sizeof(int)*max_size);
	heap->size = 0;
	heap->max_size = max_size;
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr)
{
	if(heap->size<heap->max_size)
	{
		for (int i=heap->size;i>0;i--)
		{
			*count_ptr+=1;
			heap->arr[i] =  heap->arr[i-1];
		}
		heap->arr[0] = key;
		heap->size++;
		int temp = 0;int max;
		
		while(2*temp+1<heap->size)
		{
			*count_ptr+=1;
			max = heap->arr[temp];
			if(max < heap->arr[2*temp+1])
				max = heap->arr[2*temp+1];
			if (2*temp+2<heap->size && max < heap->arr[2*temp+2])
			{
				max = heap->arr[2*temp+2];
				heap->arr[2*temp+2] = heap->arr[temp];
				heap->arr[temp] = max;
				temp = 2*temp+2;
			}
			else if(max != heap->arr[temp])
			{
				heap->arr[2*temp+1] = heap->arr[temp];
				heap->arr[temp] = max;
				temp = 2*temp+1;
			}
			else
				temp = heap->size;
		}
	}
	
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr)
{
	int max_ele = heap->arr[0];
	heap->size --;
	heap->arr[0] = heap->arr[heap->size];
	*count_ptr+=1;
	int temp = 0;int max;
	while(2*temp+1<heap->size)
	{
		*count_ptr+=1;
		max = heap->arr[temp];
		if(max < heap->arr[2*temp+1])
			max = heap->arr[2*temp+1];
		if (2*temp+2<heap->size && max < heap->arr[2*temp+2])
		{
			max = heap->arr[2*temp+2];
			heap->arr[2*temp+2] = heap->arr[temp];
			heap->arr[temp] = max;
			temp = 2*temp+2;
		}
		else if(max != heap->arr[temp])
		{
			heap->arr[2*temp+1] = heap->arr[temp];
			heap->arr[temp] = max;
			temp = 2*temp+1;
		}
		else
			temp = heap->size;
	}
	return max_ele;
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr) 
{
	int temp = 0;
	int stack[heap->size];int c=0;
	if(heap->arr[temp]==key)
	{
		*count_ptr+=1;
		return key;
	}
	while(2*temp+1<heap->size || c!=0)
	{	
		*count_ptr+=1;
		if(2*temp+1>=heap->size)
		{
			c--;
			temp = stack[c];
		}
		if(heap->arr[temp]==key)
			return key;
		else if(key>heap->arr[2*temp+1] && key>heap->arr[2*temp+2])
			return -1;
		else if(key>heap->arr[2*temp+1])
			temp = 2*temp+2;
		else if(key>heap->arr[2*temp+2])
			temp = 2*temp+1;
		else 
		{
			temp = 2*temp+1;
			stack[c] = 2*temp+2;c++;
		}
	}
	*count_ptr+=1;
	return -1;
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr)
{
	*count_ptr+=1;
	return heap->arr[0];
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr)
{
	
	int i = (heap->size-1)/2;int min=heap->arr[i];
	for(;i<heap->size;i++)
	{
		*count_ptr+=1;
		if(heap->arr[i]<min)
			min = heap->arr[i];
	}
	return min;
}

// Clears the heap for reuse
void clear_heap(heap_t *heap)
{
	for(int i=0;i<heap->size;i++){
		heap->arr[i]= 0;
	}
	heap->size = 0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap)
{
	free(heap->arr);
	//free(heap);heap = NULL;
	heap->arr = NULL;
	heap->size = 0;
	heap->max_size = 0;
}
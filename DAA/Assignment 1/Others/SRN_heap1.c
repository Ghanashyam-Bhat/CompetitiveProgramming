// Name:
// SRN: 
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
	heap->arr = (int*)calloc(max_size,sizeof(int));
	heap->size = 0;
}
static int sqrtr(int n)
{
	int temp;
	for(int i=1;i<n;i++)
	{
		if(i*i>n)
			return temp;
		else 
			temp = i;
	}
}
// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
static void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
static void sort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
void insert(heap_t *heap, int key, int *count_ptr)
{	
	heap->arr[heap->size] = key;
	sort(heap->arr,heap->size);	
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr)
{
	int max_ele = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size-1];
	heap->size -= 1;
	sort(heap->arr,heap->size);
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr) 
{
	for(int i=0;i<heap->max_size;i++)
	{
		if(heap->arr[i]==key)
			return heap->arr[i];
	}
	return -1
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr)
{
	int max = heap->arr[0];
	for(int i=0;i<heap->max_size;i++)
	{
		if(heap->arr[i]>max)
			max = heap->arr[i];
	}
	return max
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr)
{
	int min = heap->arr[0];
	for(int i=0;i<heap->max_size;i++)
	{
		if(heap->arr[i]<max)
			min = heap->arr[i];
	}
	return min
}

// Clears the heap for reuse
void clear_heap(heap_t *heap)
{
	heap->size = 0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap)
{
	free(heap->arr);
}
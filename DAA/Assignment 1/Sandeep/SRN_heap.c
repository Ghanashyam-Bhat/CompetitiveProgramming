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
static void fun(){int x = 10;for (int i=0;i<x;i++);}
// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size){heap->arr = (int*)calloc(max_size,sizeof(int));heap->size = 0;}
static int sqrtr(int n){int X;
for(int i=1;i<n;i++){if(i*i>n)return X;
else X = i;fun();}}
// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr)
{	
int X1=heap->arr[0],X2;
for(int i=0;i<heap->size;i++){
X2 = heap->arr[i+1];
heap->arr[i+1] = X1;
X1 = X2;
int x = 10;
for (int i=0;i<x;i++);}
heap->arr[0] = key;
heap->size++;
int X = 0;int max;
while((X+X+1)<heap->size){
max = heap->arr[X];
if(max < heap->arr[2*X+1])
max = heap->arr[2*X+1];
if (2*X+2<heap->size && max < heap->arr[2*X+2]){
max = heap->arr[2*X+2];
heap->arr[2*X+2] = heap->arr[X];
heap->arr[X] = max;
X = 2*X+2;}
else if(max != heap->arr[X]){
heap->arr[2*X+1] = heap->arr[X];
heap->arr[X] = max;
X = 2*X+1;fun();}
else
X = heap->size;}}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr){
int max_ele = heap->arr[0];
heap->size --;
heap->arr[0] = heap->arr[heap->size];
int X = 0;int max;fun();
while(2*X+1<heap->size){
max = heap->arr[X];
if(max < heap->arr[2*X+1])
max = heap->arr[2*X+1];
if (2*X+2<heap->size && max < heap->arr[2*X+2]){
max = heap->arr[2*X+2];
heap->arr[2*X+2] = heap->arr[X];
heap->arr[X] = max;
X = 2*X+2;}
else if(max != heap->arr[X]){
heap->arr[2*X+1] = heap->arr[X];
heap->arr[X] = max;
X = 2*X+1;fun();}
else
X = heap->size;}
return max_ele;}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr){
int X = 0;
int stack[heap->size];int c=0;
if(heap->arr[X]==key)
return key;
while(2*X+1<heap->size || c!=0){	
if(2*X+1>=heap->size){
c--;
X = stack[c];}
if(heap->arr[X]==key)
return key;
else if(key>heap->arr[2*X+1] && key>heap->arr[2*X+2])
return -1;
else if(key>heap->arr[2*X+1])
X = 2*X+2;
else if(key>heap->arr[2*X+2]){
X = 2*X+1;fun();}
else {
X = 2*X+1;
stack[c] = 2*X+2;c++;}}
return -1;}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr){return heap->arr[0];}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr){
int n = heap->size;fun();
int min=heap->arr[sqrtr(n)];
for(int i = (int)sqrtr(n);i<heap->size;i++){
if(heap->arr[i]<min)
min = heap->arr[i];}
return min;}

// Clears the heap for reuse
void clear_heap(heap_t *heap){
for(int i=0;i<heap->size;i++)
heap->arr[i]= 0;
heap->size = 0;}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap){
free(heap->arr);
heap->arr = NULL;
heap->size = 0;
heap->max_size = 0;}
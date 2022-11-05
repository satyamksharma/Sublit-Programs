/*Create a min heap out of an array of N integers of a certain size S. You will be implementing a bottom up approach to this. 

A Min Heap is a Tree where the root node has the most minimum key in the tree. Every node is smaller than its children. 
The above definition holds true for all sub-trees in the tree. This is called the Min Heap property. It is important to note that heaps are not always sorted, the key condition that they follow is that the largest or smallest element is placed on the root node (top) depending if it is a Max or Min Heap. 

The array maintains a 0-based index.

You are required to implement the following tree operations as a part of this lab exercise:
1. void create_minheap(MinHeap *heap) 
* A function that takes in a struct heap, which includes an array and size of that array, and adjusts the heap in a bottom up manner from the last parent index (size/2) up to the root, by comparing it with children. 

2. void print_minheap(MinHeap* heap);
* Implement this function that traverses all elements in the final constructed heap in the form of an array, until the size of the array. You needn't call this function anywhere, it is handled by the main program. You only need to implement it. Do not call it anywhere else. 

The skeleton of the min heap is provided to you via “struct” so you need not code that. 
Functions to initialise minheap, and free min heap has already been implemented in the boilerplate code. 
USING THE BOILERPLATE CODE PROVIDED IS MANDATORY.

Input Format

Each test case starts with an input of 2 lines. 
First line of input consists of an integer N, representing the size of the array, which is the number of elements that it holds. 
Second line consists of an array of space separated integers out of which you'll be constructing a min heap. 

Output Format

The output will be an array of space separated integers which is actually the level order traversal of the min heap printed using the print_heap method.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};


MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}

void create_minheap(MinHeap *heap) 
{
	int c,p,key;
	
	for(int i=heap->size/2-1;i>=0;i--)
	{
		p=i;
		c=2*p+1;
		key=heap->arr[p];
		
		while(c<heap->size)
		{
			if(c+1 < heap->size)
			{
				if(heap->arr[c+1]<heap->arr[c])
					c=c+1;
			}
			if(key > heap->arr[c])
			{
				heap->arr[p]=heap->arr[c];
				p=c;
				c=2*p+1;
			}
			else
				break;
		}
		heap->arr[p]=key;
	}

}



void print_minheap(MinHeap* heap) {
    for(int i=0;i<heap->size;i++)
	{
		printf("%d ",heap->arr[i]);
	}
}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        scanf("%d", &heap->arr[i++]);

    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}
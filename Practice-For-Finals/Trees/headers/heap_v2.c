#include <stdio.h>
#include <stdlib.h>
#include "heap_v1.h"
#include <math.h>

Heaplist init() 
{
    Heaplist start = {
        {4,5,9,8,6,9,10,10,18,9},
        10
    };
    return start;
}

void insert(Heaplist *heap, int val) 
{
    int pdx;
    if (heap->count < SIZE) {
        heap->heap[heap->count++] = val;
        for (pdx = floor((heap->count-2)/2); pdx > -1; pdx--) {
            heapify(heap, pdx);
        }
    } else {
        printf("Heap is full. Full Binary Tree!\n");
    }
}

void heapify(Heaplist *heap, int parent)
{
    int sdx = parent, temp;
    //Checks the right child
    if (parent*2+1 < heap->count && heap->heap[parent*2+1] < heap->heap[sdx]) {sdx = parent*2+1;}
    //Checks the left child
    if (parent*2+2 < heap->count && heap->heap[parent*2+2] < heap->heap[sdx]) {sdx = parent*2+2;}
    //If the parent == sdx, the sdx remained the same. Hence no swap needed since the parent property is fulfilled
    if (sdx != parent) {
        temp = heap->heap[parent];
        heap->heap[parent] = heap->heap[sdx];
        heap->heap[sdx] = temp;
    }
}

void printHeap(Heaplist heap)
{
    int i;
    for (i = 0;  i < heap.count; ++i) {printf("%d ", heap.heap[i]);}
    printf("\nCurrent count: %d\n", heap.count);
}


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
    if (heap->count < SIZE) {
        heap->heap[heap->count++] = val;
        heapify(heap);
    } else {
        printf("Heap is full. Full Binary Tree!\n");
    }
}

void heapify(Heaplist *heap)
{
    int pdx, temp, sdx;
    if (heap->count <= SIZE) {
        for (pdx = floor((heap->count-2)/2); pdx > -1 ;pdx--) {
            sdx = pdx;
            if (pdx*2+1 < heap->count && heap->heap[pdx*2+1] < heap->heap[sdx]) {
                sdx = pdx*2+1;
            }
            if (pdx*2+2 < heap->count && heap->heap[pdx*2+2] < heap->heap[sdx]) {
                sdx = pdx*2+2;
            }
            if (sdx != pdx) {
                temp = heap->heap[pdx];
                heap->heap[pdx] = heap->heap[sdx];
                heap->heap[sdx] = temp;
            }
        }
    }
}

void printHeap(Heaplist heap)
{
    int i;
    for (i = 0;  i < heap.count; ++i) {printf("%d ", heap.heap[i]);}
    printf("\nCurrent count: %d\n", heap.count);
}


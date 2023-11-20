#ifndef HEAP_TREES_V1
#define HEAP_TREES_V1

#define SIZE 14

typedef struct heaplist
{
    int heap[SIZE];
    int count;
}
Heaplist;

Heaplist init();
void insert(Heaplist *heap, int val);
void heapify(Heaplist *heap, int parent);
void printHeap(Heaplist heap);
int deletemin();

#endif
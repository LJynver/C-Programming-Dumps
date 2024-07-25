#include <stdio.h>
#include "headers/heap_v2.h"
#include "headers/heap_v2.c"

int main ()
{

    Heaplist head = init();

    printHeap(head);

    insert(&head, 15);

    printHeap(head);

    return 0;
}
#include <stdio.h>
#include "headers/heap_v1.h"
#include "headers/heap_v1.c"

int main ()
{

    Heaplist head = init();

    printHeap(head);

    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);

    printHeap(head);

    

    return 0;
}
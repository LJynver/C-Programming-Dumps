/******************************** INTRODUCTION TO STACKS *******************************************/
/**************** A STACK IS A DATA STRUCTURE THAT FOLLOWS THE LIFO PRINCIPLE **********************/
/*********************** MEANING THE LAST ELEMENT TO BE INSERTED (PUSH) ****************************/
/************************** IS THE FIRST ELEMENT TO BE DELETED (POP) *******************************/
/*************** DO NOTE THAT YOU CAN ONLY MANIPULATE THE TOPMOST ELEMENT ONLY *********************/
/************ TOPMOST = MOST RECENTLY PUSHED ELEMENT/CURRENT ELEMENT AFTER A POP OPERATION *********/
/************* THIS MEANS POP AND PUSH OPERATIONS ARE TO BE DONE ON THE TOPMOST ELEMENT ************/
/************************** NO TRAVERSALS. PRINTING LIST IS NOT ALOUD ******************************/
/********** FOR THE SAKE OF READABILITY, I MADE A PRINT FUNCTION FOR YOU TO GET A GRASP OF SUCH ****/
/*** BUT IN ASSESSMENTS, AVOID ANY FUNCTION THAT MAKES USE OF TRAVERSALS LIKE PRINTING ELEMENTS ****/

/********************* BELOW IS AN EXAMPLE OF STACKS USING VERSION 3 OF ARRAY LIST *****************/

/******************************* LIFO = LAST IN, FIRST OUT *****************************************/
/******************************* TEMPLATE MADE BY, LYAN :DD ****************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct list {
    int *arr;
    int count;
} LIST;

LIST initList();
void pushToList(LIST *L, int data);
void popList(LIST *L);
void displayList(LIST head); //this function should not be imnplemented when in a STACKS opertation

int main () {

    LIST main = initList();

    pushToList(&main, 1);
    pushToList(&main, 2);
    pushToList(&main, 6);
    pushToList(&main, 5);
    pushToList(&main, 4);
    pushToList(&main, 7);
    pushToList(&main, 9);
    pushToList(&main, 3); //last element to get that last slot
    pushToList(&main, 11); //9th element to insert, will display the message because no slot is available

    displayList(main);

    popList(&main);
    displayList(main);
    popList(&main);
    displayList(main);
    popList(&main);
    displayList(main);

    return 0;
}

LIST initList() {
    LIST start = {.arr = (int*)malloc(sizeof(int)*MAX)};

    if (start.arr != NULL) {
        start.count = 0;
    }

    return start;
}

void pushToList(LIST *L, int data) {
    int pos = L->count;
    if (L->count < MAX) {
        L->arr[pos] = data;
        L->count++;
        //for the sake of readability only
        //shortcut you can put L->count right away as the index
    } else {
        printf("\nUnable to insert due to insufficient space!\n");
    }
}

void popList(LIST *L) {
    if (L->count > -1) {
        L->count--; 
        //even if this is decremented, the data is still there. Linked Lists can remove this in memory
        //However there is no need to worry about so, since this data will be overwritten the next time you pushed a data
    } else {
        printf("\nOut of bounds! The array is already empty!\n");
    }
}

void displayList(LIST head) {
    int ndx;
    for (ndx = 0;  ndx < head.count; printf(" [%d] ", head.arr[ndx]), ++ndx) {} //note that we are using the L.count, not the MAX
    //MAX is the maximum we can hold in the array
    //Count is the variable that actually counts what is in the array
    //Try changing it into MAX. What do you see?
    printf("\n");
}
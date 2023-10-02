#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

//open hashing

typedef enum {FALSE, TRUE} Boolean;

typedef struct nodes {
    int data;
    struct nodes *next;
} *List;

typedef List Dictionary[SIZE];

void initHTable(Dictionary table);
int hashFunction(int elem);
Boolean isMember(Dictionary table, int elem);
void insertHash(Dictionary table, int elem);
void displayHTable(Dictionary table);
void deleteHTable(Dictionary table, int elem);

int main () {

    Dictionary main;
    initHTable(main);

    insertHash(main, 1);
    insertHash(main, 5);
    insertHash(main, 4);
    insertHash(main, 1);
    insertHash(main, 2);
    insertHash(main, 11);
    insertHash(main, 23);
    insertHash(main, 99);


    displayHTable(main);

    deleteHTable(main, 91);
    deleteHTable(main, 11);

    displayHTable(main);

    return 0;
}

void initHTable(Dictionary table) {
    int i;
    for (i = 0; i < SIZE; ++i) {
        table[i] = NULL;
    }
}

int hashFunction(int elem) {
    return elem % SIZE;
}

Boolean isMember(Dictionary table, int elem) {
    int pos = hashFunction(elem);
    List trav;
    for (trav = table[pos]; trav != NULL && trav->data != elem; trav = trav->next) {}
    return (trav != NULL) ? TRUE : FALSE ;
}

void insertHash(Dictionary table, int elem) {
    if (!isMember(table, elem)) {
        int pos = hashFunction(elem);
        List temp = (List)malloc(sizeof(struct nodes));
        if (temp != NULL) {
            temp->data = elem;
            temp->next = table[pos];
            table[pos] = temp;
        }
    } else {
        printf("\nNot unique!\n");
    }
}

void displayHTable(Dictionary table) {
    int ndx;
    List trav;
    for (ndx = 0; ndx < SIZE; ++ndx) {
        printf("[%d] => ", ndx);
        for (trav = table[ndx]; trav != NULL; trav = trav->next) {
            (trav->next != NULL) ? printf("(%d) -> ", trav->data) : printf("(%d)", trav->data);
        }
        printf("\n");
    }
}

void deleteHTable(Dictionary table, int elem) {
    if (isMember(table, elem)) {
        int pos = hashFunction(elem);
        List *trav = &table[pos];
        for (; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next) {}
        if (*trav != NULL) {
            List temp = *trav;
            *trav = temp->next;
            free(temp);
        }
    } else {
        printf("\nMember does not exist!\n");
    }
}
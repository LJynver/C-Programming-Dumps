#include <stdio.h>
#include <stdlib.h>

//File is not mine

typedef struct nodes {
    int data;
    struct nodes *link;
} *SET;

SET initSet();
void insertSortedSet(SET *S, int data);
void displaySet(SET D);
SET intersectSet(SET A, SET B);

int main () {

    SET A = initSet();
    SET B = initSet();

    insertSortedSet(&A, 1);
    insertSortedSet(&A, 9);
    insertSortedSet(&A, 4);
    insertSortedSet(&A, 3);
    insertSortedSet(&A, 5);

    printf("SET A: ");
    displaySet(A);

    insertSortedSet(&B, 7);
    insertSortedSet(&B, 6);
    insertSortedSet(&B, 3);
    insertSortedSet(&B, 4);
    insertSortedSet(&B, 7);

    printf("SET B: ");
    displaySet(B);

    SET C = intersectSet(A, B);

    return 0;
}

SET initSet() {
    return NULL;
}

void insertSortedSet(SET *S, int data) {
    SET *trav = S;
    for (; *trav != NULL && data > (*trav)->data; trav = &(*trav)->link) {}
    if (*trav == NULL || (*trav)->data != data) {
        SET temp = (SET)malloc(sizeof(struct nodes));
        if (temp != NULL) {
            temp->data = data;
            temp->link = *trav;
            *trav = temp;
        }
    }
}

void displaySet(SET D) {
    for (; D != NULL; D = D->link) {
        (D->link != NULL) ? printf(" [%d] -> ", D->data) : printf(" [%d] ", D->data);
    }
    printf("\n");
}

SET intersectSet(SET A, SET B) {
    SET result = NULL, temp = NULL;
    while (A != NULL && B != NULL) {
        if (A->data == B->data) {
        	printf("HELLO");
            temp = (SET)malloc(sizeof(struct nodes));
            if (temp != NULL) {
                temp->data = A->data;
                temp->link = result;
                result = temp;
            }
        } else {
            if (A->data < B->data) {
                A = A->link;
            } else {
                B = B->link;
            }
        }
    }
    return result;
}
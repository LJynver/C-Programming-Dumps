#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
    int data;
    struct nodes *link;
} *SET;

SET initSet();
void insertSorted(SET *S, int data);
SET unionSet(SET A, SET B);
SET intersectionSet(SET A, SET B);
void displayList(SET D);

int main () {

    SET A = initSet();
    SET B = initSet();

    insertSorted(&A, 1);
    insertSorted(&A, 5);
    insertSorted(&A, 3);
    insertSorted(&A, 6);

    printf("SET A: ");
    displayList(A);
    
    insertSorted(&B, 3);
    insertSorted(&B, 2);
    insertSorted(&B, 7);
    insertSorted(&B, 8);
    insertSorted(&B, 9);
    insertSorted(&B, 5);

    printf("SET B: ");
    displayList(B);

    SET C = unionSet(A, B);
    printf("SET C (Union): ");
    displayList(C);

    SET D = intersectionSet(A, B);
    printf("SET D (Intersection): ");
    displayList(D);

    return 0;
}

SET initSet() {
    SET start = NULL;
    return start;
}

void insertSorted(SET *S, int data) {
    SET *trav = S;
    SET temp = (SET)malloc(sizeof(struct nodes));
    if (temp != NULL) {
        for (; *trav != NULL && (*trav)->data < data; trav = &(*trav)->link) {}
        temp->data = data;
        temp->link = *trav;
        *trav = temp;
    }
}

SET unionSet(SET A, SET B) {
    SET result = NULL;
    SET temp; //for insertion
    SET *trav = &result; //moves after insertion

    while (A != NULL && B != NULL) {
        temp = (SET)malloc(sizeof(struct nodes));
        if (temp != NULL) {

            if (A->data < B->data) { 
                temp->data = A->data;
                A = A->link;
            } else if (A->data > B->data) { 
                temp->data = B->data;
                B = B->link;
            } else { 
                temp->data = A->data;
                A = A->link;
                B = B->link;
            }
            temp->link = NULL;
            *trav = temp;
            trav = &(*trav)->link;

        }
    }

    if (A != NULL) {
        *trav = A;
    } else if (B != NULL) {
        *trav = B;
    }

    return result;
}

SET intersectionSet(SET A, SET B) {
    SET result = NULL;
    SET temp; //for insertion
    SET *trav = &result; //moves after insertion

    while (A != NULL && B != NULL) {
            if (A->data == B->data) {
                temp = (SET)malloc(sizeof(struct nodes));
                if (temp != NULL) {
                    temp->data = A->data;
                    temp->link = *trav;
                    *trav = temp;
                    trav = &(*trav)->link;
                }
                A = A->link;
                B = B->link;
            } else {
                if (A->data < B->data) {
                    A = A->link;
                } else if (A->data > B->data) {
                    B = B->link;
                } 
            }

        }

    return result;
}

void displayList(SET D) {
    for (; D != NULL; D = D->link) {
        (D->link != NULL) ? printf(" [%d] -> ", D->data) : printf(" [%d] ", D->data);
    } printf("\n");
}
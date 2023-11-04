#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
} Node;

Node *init(int rootNum);

int main () {

    Node *root = init(10);

    return 0;
}

Node *init(int rootNum) {
    Node *start = (Node*)malloc(sizeof(Node));
    if (start != NULL) {
        start->val = rootNum;
    }
    return start;
}
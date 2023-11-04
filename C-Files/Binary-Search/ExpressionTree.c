#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char data;
    struct node *lchild, *next, *rchild;
} Node;

Node *newNode(char val); //creates the new node
void pushStack(Node **head, Node *memberNode); //pushes to the stack and update the top node
Node *popStack(Node **head); //pop the current top node and return the popped node
void split(Node **head, Node *operatorNode); //form a tree when an operator is encountered
void inOrder(Node *start); //print the tree in the inOrder traversal

int main () {

    char s[] = {'A', 'B', 'C', '*', '+', 'D', '/'}; //array of characters
    int sz = sizeof(s) / sizeof(s[0]), i;
    Node *head = NULL, *temp = NULL;
    //head will serve as the top of the stack
    //temporary will serve as catcher for the newNode function

    for (i = 0; i < sz; ++i) {
        if (isalnum(s[i]) != 0) { //if the value at a particular index is alphanumeric
            temp = newNode(s[i]);
            pushStack(&head, temp);
            temp = NULL;
        } else { //if it is an operator symbol
            temp = newNode(s[i]);
            split(&head, temp);
        }
    }

    inOrder(head);

    return 0;
}

Node *newNode(char val) {
    Node *member = (Node*)malloc(sizeof(Node));
    if (member != NULL) {
        member->data = val;
        member->lchild = member->next = member->rchild = NULL;
    }
    return member;
}

void pushStack(Node **head, Node *memberNode) {
    memberNode->next = *head;
    *head = memberNode;
}

void split(Node **head, Node *operatorNode) {
    Node *left, *right;
    if (*head == NULL && (*head)->next == NULL) {
        printf("\nNeeds a right value\n");
    } else {
        right = popStack(head);
        left = popStack(head);
        operatorNode->lchild = left;
        operatorNode->rchild = right;
        pushStack(head, operatorNode);
    }
}

Node *popStack(Node **head) {
    Node *temp = *head;
    *head = temp->next;
    temp->next = NULL; //removes the pointer next from pointing to the next stack element
    return temp;
}

void inOrder(Node *start) { //recursive function
    if (start != NULL) {
        inOrder(start->lchild);
        printf(" %c ", start->data);
        inOrder(start->rchild);
    }
}
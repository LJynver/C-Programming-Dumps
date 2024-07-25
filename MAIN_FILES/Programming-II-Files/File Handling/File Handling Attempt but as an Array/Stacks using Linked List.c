#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
	int data;
	struct node* next;
} Node, *Link;

Link head = NULL;

void push(int data);
void display();
void pop();

int main () {
	
	return 0;
}

void push(int data) {
	Link newNode = (Link)malloc(sizeof(Node));
	newNode->data = data;
	if (head == NULL) {
		newNode->next = head;
		head = newNode;
	} else {
		Link trav;
		for (trav = head; trav->next != NULL; trav=trav->next) {}
		newNode->next = trav->next;
		trav->next = newNode;
	}
}

void display() {
	Link trav;
	for (trav = head; trav != NULL; printf(" [ %d ] ", trav->data), trav=trav->next) {}
	printf("\n");
}

void pop() {
	Link trav;
	for (trav = head; trav->next->next != NULL; trav=trav->next) {}
	free(trav->next->next);
	trav->next = NULL;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *link;	
}Node, *List;

void insertElement(int data, List *main);

/* Function to insert a node to the last section of the linked list */

void displayList(List display);

/* For displaying the Linked List */

void removeInstance(int data, List *main);

/* This removes any duplicate data from the given Linked List */

int main () {
	
	List head = NULL;
	
	insertElement(6, &head);
	insertElement(3, &head);
	insertElement(7, &head);
	insertElement(6, &head);
	insertElement(4, &head);
	
	displayList(head);
	
	removeInstance(6, &head);
	displayList(head);
	
	return 0;
}

void insertElement(int data, List *main) {
	List *trav = main;
	for (; *trav != NULL; trav = &(*trav)->link) {}
	//butterfly notation for quick traversal
	if (*trav == NULL) {
		//means the trav variable has reached to the last node
		List newNode = (List)malloc(sizeof(Node));
		if (newNode != NULL) { //checks if memory allocation was successful
			newNode->data = data;
			newNode->link = *trav;
			*trav = newNode;
		}
	}
}

void removeInstance(int data, List *main) {
	List *trav = main, temp = NULL;
	/* trav will traverse, temp will get the dereferenced trav value */
	while (*trav != NULL) {
		temp = *trav;
		if ((*trav)->data == data) {
			*trav = (*trav)->link;
			temp->link = NULL;
			free(temp);
			//deallocating the pointed node
		} else {
			trav = &(*trav)->link;
		}
	}
}

void displayList(List display) {
	while (display) {
		(display->link != NULL) ? printf("[%d] -> ", display->data) : printf("[%d]", display->data); 
		//ternary operator to display all data items in the node
		display = display->link;
	}
	printf("\n");
}

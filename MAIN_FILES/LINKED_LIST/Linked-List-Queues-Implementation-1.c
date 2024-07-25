#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} NODE, *LINK;

void pushToLast(int num, LINK *H);
void displayList(LINK D);
void *isFirst(LINK H);
void *isLast(LINK H);
void popQueue(LINK *H);

int main () {
	
	LINK main = NULL;
	
	pushToLast(6, &main);
	pushToLast(7, &main);
	pushToLast(9, &main);
	displayList(main);
	
	pushToLast(9, &main);
	displayList(main);
	
	pushToLast(10, &main);
	pushToLast(11, &main);
	pushToLast(12, &main);
	displayList(main);
	pushToLast(13, &main);
	pushToLast(13, &main);
	pushToLast(15, &main);
	displayList(main);
	
	printf("\nThe first element in the list is: %d\n", *((int*)isFirst(main)));
	printf("The last element in the list is: %d\n\n", *((int*)isLast(main)));
	
	popQueue(&main);
	displayList(main);
	printf("\nThe first element in the list is: %d\n", *((int*)isFirst(main)));
	printf("The last element in the list is: %d\n\n", *((int*)isLast(main)));
	
	popQueue(&main);
	displayList(main);
	printf("\nThe first element in the list is: %d\n", *((int*)isFirst(main)));
	printf("The last element in the list is: %d\n\n", *((int*)isLast(main)));

	return 0;
}

void pushToLast(int num, LINK *H) {
	LINK *trav;
	for (trav = H; *trav != NULL && (*trav)->data != num; trav = &(*trav)->next) {}
	if (*trav == NULL) {
		LINK newNode = (LINK)malloc(sizeof(newNode));
		newNode->data = num;
		newNode->next = *trav;
		*trav = newNode;
	}
}

void displayList(LINK D) {
	while (D != NULL) {
		(D->next != NULL) ? printf("[%d] --> ", D->data): printf("[%d]\n", D->data);
		D = D->next;
	}
}

void *isFirst(LINK H) {
	return &(H->data);
}

void *isLast(LINK H) {
	while (H->next != NULL) {H=H->next;}
	return &(H->data);
}

void popQueue(LINK *H) {
	LINK shiftNode = *H;
	*H = shiftNode->next;
	shiftNode->next = NULL;
	free(shiftNode);
}
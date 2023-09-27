#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct node {
	char data;
	struct node *link;
} NODE, *LIST;

void insertLastUnique(char element, LIST* A);
void displayList(LIST H);

int main () {
	char elem = NULL;
	LIST L = NULL;
	
	char choice = NULL;
	do {
		printf("Enter a character for insertion: ");
		scanf(" %c", &elem);
		insertLastUnique(elem, &L);
		do {
			printf("Do you want to insert another? [Y for Yes/N for No] ");
			scanf(" %c", &choice);
			choice = tolower(choice);		
		} while (choice != 'n' && choice != 'y');
		(choice == 'n') ? exit(0) : system("cls");
	} while (choice != 'n');
	
	return 0;
}

void insertLastUnique(char element, LIST* A) {
	LIST *trav;
	for (trav = A; *trav != NULL && (*trav)->data != element; trav = &(*trav)->link) {}
	if (*trav == NULL) {
		LIST newNode = (LIST)malloc(sizeof(NODE));
		newNode->data = element;
		newNode->link = *trav;
		*trav = newNode;
	}
	displayList(*A);
}

void displayList(LIST H) {
	printf("Current list: ");
	while (H != NULL) {
		printf("[ %c ]", H->data);
		(H->link != NULL) ? printf(" -> ") : printf("");
		H = H->link;
	}
	printf("\n\n");
}

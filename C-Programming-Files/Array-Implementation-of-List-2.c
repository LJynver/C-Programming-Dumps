#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/* Initialization happens in the main function 
 Initialization function will be on the work */

typedef struct node {
	void *elemPtr;
	int count;
}List;

/* Void pointer here is used since it allows it to point to any data type
 When the time comes we need to assign a value, all we need is to typecast it
  Before dereferencing the pointer */

void insertElement(char data, List *head);
void removeInstances(char data, List *head);
void displayArrayImp(List head);

int main () {
	
	List L = {.count = 0, .elemPtr = malloc(MAX)};
	insertElement('H', &L);
	insertElement('E', &L);
	insertElement('L', &L);
	insertElement('L', &L);
	insertElement('O', &L);
	insertElement('O', &L);
	displayArrayImp(L);
	
	removeInstances('O', &L);
	displayArrayImp(L);
	
	return 0;
}

void insertElement(char data, List *head) {
	int i = head->count++;
	((char*)head->elemPtr)[i] = data;
}

void displayArrayImp(List head) {
	int i;
	for (i=0; i < head.count; printf("%c ", ((char*)head.elemPtr)[i]), ++i) {}
	printf("\n");
}

void removeInstances(char data, List *head) {
	int i = 0, j;
	while (i < head->count) {
		j = i;
		if (((char*)head->elemPtr)[i] == data) {
			head->count--;
			for (; j < head->count; ((char*)head->elemPtr)[j] = ((char*)head->elemPtr)[j+1], ++j) {}
			((char*)head->elemPtr)[j] = '\0';
		} else {
			++i;
		}
	}
}

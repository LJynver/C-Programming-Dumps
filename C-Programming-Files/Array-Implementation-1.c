#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//this is if List is a pointer to a struture

typedef struct node {
	char elements[MAX];
	int count;
}*List;

void removeInstances(char data, List head);
void displayArrayImp(List head);

int main () {
	
	struct node main = {
		.elements[0] = 'H',
		.elements[1] = 'O',
		.elements[2] = 'P',
		.elements[3] = 'E',
		.elements[4] = 'E',
		.count = 5
	};
	
	List L = &main;
	displayArrayImp(L);
	removeInstances('E', L);
	displayArrayImp(L);
	
	return 0;
}

void removeInstances(char data, List head) {
	int i = 0, j;
	while (i < head->count) {
		j = i;
		if (head->elements[i] == data) {
			head->count--;
			for (; j < head->count; head->elements[j] = head->elements[j+1], ++j) {}
			head->elements[j] = '\0';
		} else {
			++i;
		}
	}
}

void displayArrayImp(List head) {
	int i;
	for (i = 0; i < head->count; printf("%c ", head->elements[i]), ++i) {}
	printf("\n");
}

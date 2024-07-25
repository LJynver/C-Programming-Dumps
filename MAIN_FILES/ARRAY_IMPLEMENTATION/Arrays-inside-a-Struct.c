#include <stdio.h>
#define MAX 8

typedef struct node {
	char elem[MAX];
	int count;
}LIST;

void insertLast(char element, LIST *main);
void displayListArr(LIST *main);

int main () {
	LIST L = {.count = 0};
	insertLast('C', &L);
	insertLast('A', &L);
	insertLast('B', &L);
	insertLast('C', &L);
	insertLast('D', &L);
	insertLast('F', &L);
	displayListArr(&L);
	
	return 0;
}

void insertLast(char element, LIST *main) {
	int i;
	if (main->count < MAX) {
		for (i = 0; i < main->count && main->elem[i] != element; i++) {}
		(i == main->count) ? main->elem[main->count++] = element : 0;
	}
}

void displayListArr(LIST *main) {
	int i;
	for (i = 0; i < main->count; printf("%c\n", main->elem[i]), i++) {}
}
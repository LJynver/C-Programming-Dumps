#include <stdio.h>
#define MAX 8

typedef struct node {
	char elem[MAX];
	int count;
}LIST;

void insertLast(char element, LIST *main);
void displayListArr(LIST *main);
void removeInstance(char element, LIST *main);

int main () {
	LIST L;
	insertLast('C', &L);
	insertLast('A', &L);
	insertLast('B', &L);
	insertLast('C', &L);
	insertLast('D', &L);
	insertLast('F', &L);
	L.count = 6;
	displayListArr(&L);
	
	removeInstance('A', &L);
	displayListArr(&L);
	return 0;
}

void insertLast(char element, LIST *main) {
	int i;
	if (main->count < MAX) {
		for (i = 0; i < main->count; i++) {}
		(i == main->count) ? main->elem[main->count++] = element : 0;
	}
}

void displayListArr(LIST *main) {
	int i;
	for (i = 0; i < main->count; printf("%c ", main->elem[i]), i++) {}
	printf("\n");
}

void removeInstance(char element, LIST *main) {
	int i = 0, j;
	while (i < main->count) {
		j = i;
		if (main->elem[i] == element) {
			 main->count--;
			 for (; j < main->count; main->elem[j] = main->elem[j+1], ++j) {}
			 main->elem[main->count] = 0;
		} else {
			++i;
		}
	}
}
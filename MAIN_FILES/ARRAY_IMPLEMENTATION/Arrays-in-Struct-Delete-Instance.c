#include <stdio.h>
#define MAX 8

typedef struct node {
	char elem[MAX];
	int count;
}LIST;

/* An array is inside a struct with a size of 8 elements
 The count variable in the struct determines the
 actual number of elements, not the overall */

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
        //for loop to traverse to the end
		(i == main->count) ? main->elem[main->count++] = element : 0;
        //checks if the iterator has the same value as the count
	}
}

void displayListArr(LIST *main) {
	int i;
	for (i = 0; i < main->count; printf("%c ", main->elem[i]), i++) {}
    //a lot more line-efficient way to print it all
	printf("\n");
}

void removeInstance(char element, LIST *main) {
	int i = 0, j;
	while (i < main->count) {
		j = i;
		if (main->elem[i] == element) {
			 main->count--;
             //decrement for every similar element encountered in the array
			 for (; j < main->count; main->elem[j] = main->elem[j+1], ++j) {}
             //shift right elements to the current position
             //its basically overwriting the elements
			 main->elem[main->count] = 0;
             //last element set to 0
		} else {
			++i;
		}
	}
}
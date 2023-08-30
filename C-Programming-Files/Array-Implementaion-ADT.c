#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct node {
	char *ptr;
	int count;
}List;

List init();
void insertFrontUnique(char data, List *main);

int main () {
	
	List main = init();
	insertFrontUnique('A', &main);
	insertFrontUnique('A', &main);
	insertFrontUnique('B', &main);
	
	return 0;
}

List init() {
	List start = {
		.ptr = (char*)malloc(MAX),
		.count = -1
	};
	return start;
}

void insertFrontUnique(char data, List *main) {
	int i;
	for (i = 0; i <= main->count && main->ptr[i] != data; ++i) {}
	if (i <= MAX && i > main->count) {
		main->ptr[++main->count] = data;
	}
}

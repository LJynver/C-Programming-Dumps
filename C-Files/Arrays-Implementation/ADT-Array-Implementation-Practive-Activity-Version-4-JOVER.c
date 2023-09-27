/********************************************************

******************* PRACTICE ACTIVITY *******************
************** Array Implementation of ADT List *********
************* Version 4 of Array Implementation *********
****** Insert Function inserts elments accordingly ******
***************** Start Date: 9/2/2023 ******************
***************** End Date: 9/2/2023*********************

********************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct node {
	char *elemPtr;
	int count;
}*LIST;

LIST init();
void insertFirst(char data, LIST head);
void display(LIST head);
void removeInstances(char data, LIST head);
int isTop(LIST head);
char isFirst(LIST head);

int main () {
	
	LIST main = init();
	int top;
	char first;
	insertFirst('B', main);
	insertFirst('C', main);
	insertFirst('D', main);
	insertFirst('A', main);
	insertFirst('A', main);
	insertFirst('G', main);
	insertFirst('E', main);
	insertFirst('F', main);
	display(main);
	
	removeInstances('A', main);
	display(main);
	removeInstances('B', main);
	display(main);
	
	top = isTop(main);
	printf("\nCurrent number of elements inside: %d\nThis means the last element was: %c\n", top, main->elemPtr[top-1]);
	first = isFirst(main);
	printf("\nThe first element of the list is: %c\n", first);
	
	return 0;
}

LIST init() {
	LIST start = (LIST)malloc(sizeof(struct node));
	if (start != NULL) {
		start->elemPtr = (char*)calloc(MAX, 1);
		(start->elemPtr != NULL) ? start->count = 0 : 0 ;
	}
	return start;
}

void insertFirst(char data, LIST head) {
	if (head->count < MAX) {
		int i;
		for (i = head->count; i > 0 && head->elemPtr[i-1] > data; head->elemPtr[i] = head->elemPtr[i-1], --i) {}
		head->elemPtr[i] = data;
		head->count++;
	}
}

void display(LIST head) {
	int i;
	for (i = 0; i < head->count; printf("_%c_", head->elemPtr[i]), ++i) {}
	printf("\n\n");
}

void removeInstances(char data, LIST head) {
	int i = 0, j;
	while (i < head->count) {
		if (head->elemPtr[i] == data) {
			head->count--;
			for (j = i; j < head->count; head->elemPtr[j] = head->elemPtr[j+1], ++j) {}
			head->elemPtr[j] = '\0';
		} else {
			++i;
		}
	}
}

int isTop(LIST head) {
	return head->count;
}

char isFirst(LIST head) {
	return head->elemPtr[0];
}
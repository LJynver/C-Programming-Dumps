/********************************************************

******************* PRACTICE ACTIVITY *******************
************** Array Implementation of ADT List *********
************* Version 1 of Array Implementation *********
****** Insert Function inserts elments accordingly ******
***************** Start Date: 9/1/2023 ******************
***************** End Date: 9/1/2023*********************

********************************************************/

#include <stdio.h>
#define MAX 8

typedef struct node {
	char Elem[MAX];
	int count;
}LIST;

LIST init(); //initializing function
void insertFirst(char data, LIST *head); //insert to First
void displayList(LIST head); //displays the list
void removeInstance(char data, LIST *head); //removes any instances of given element
void popElement(); //removes the last element
int isTop(LIST head); //returns the count variable, which can be used to find the last number

int main () {
	
	LIST main = init();
	int top;
	insertFirst('C', &main);
	insertFirst('D', &main);
	insertFirst('F', &main);
	insertFirst('A', &main);
	insertFirst('A', &main);
	insertFirst('G', &main);
	displayList(main);
	top = isTop(main);
	printf("The array has %d elements insisde. Last element was: %c\n\n", top, main.Elem[top-1]);
		
	removeInstance('A', &main);
	displayList(main);
	
	top = isTop(main);
	printf("The array has %d elements insisde. Last element was: %c\n\n", top, main.Elem[top-1]);
	
	return 0;
}

LIST init() {
	LIST start = {.count = 0};
	return start;
}

void insertFirst(char data, LIST *head) {
	if (head->count < MAX) {
		int i;
		for (i = head->count; i > 0 && head->Elem[i-1] > data; head->Elem[i] = head->Elem[i-1], --i) {}
		head->Elem[i] = data;
		head->count++;
	}
}

void displayList(LIST head) {
	int i;
	for (i = 0; i < head.count; printf("_%c_", head.Elem[i]), ++i) {}
	printf("\n\n");
}

void removeInstance(char data, LIST *head) {
	int i = 0, j;
	while (i < head->count) {
		j = i;
		if (head->Elem[i] == data) {
			head->count--;
			for (; j < head->count; head->Elem[j] = head->Elem[j+1], ++j) {}
			head->Elem[j] = '\0';
		} else {
			++i;
		}
	}
}

int isTop(LIST head) {
	return head.count;
}
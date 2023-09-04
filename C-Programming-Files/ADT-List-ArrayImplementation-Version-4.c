/*************************************************************************************************/
/************************ Array Implementation Version 4 *****************************************/
/***************************** Author: Lyan Jover ************************************************/
/************** Specs: Insert Function will only add element if unique ***************************/
/******** Enum Boolean is used to catch any update states during list manipulations **************/
/*************************** Starting Date: 9/4/2023 *********************************************/
/************************** Completion Date: 9/4/2023 ********************************************/
/*************************************************************************************************/
/*************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct list {
	char *elemPtr;
	int count;
}*ArrayList;

typedef enum {FALSE, TRUE} Boolean;

ArrayList listInit();
Boolean insertToFirst(char data, ArrayList A); //this only does the operation if data input to function is unique
void displayList(ArrayList D, Boolean flag);
Boolean deleteInstance(char data, ArrayList R);

int main () {
	
	ArrayList L = listInit();	
	Boolean flag = insertToFirst('A', L);
	displayList(L, flag);
	flag = insertToFirst('C', L);
	flag = insertToFirst('E', L);
	flag = insertToFirst('F', L);
	flag = insertToFirst('D', L);
	displayList(L, flag);
	
	flag = insertToFirst('D', L);
	displayList(L, flag);
	
	flag = deleteInstance('F', L);
	displayList(L, flag);
	flag = deleteInstance('B', L);
	displayList(L, flag);
	flag = deleteInstance('A', L);
	displayList(L, flag);
	
	return 0;
}

ArrayList listInit() {
	ArrayList start = (ArrayList)malloc(sizeof(struct list));
	if (start != NULL) {
		start->elemPtr = (char*)calloc(MAX, 1);
		(start->elemPtr != NULL) ? start->count = 0 : 0;
	}
	return start;
}

Boolean insertToFirst(char data, ArrayList A) {
	Boolean retVal = FALSE;
	if (A->count < MAX) {
		int ndex;
		for (ndex = 0; ndex < A->count && A->elemPtr[ndex] != data; ++ndex) {}
		if (ndex == A->count) {
			for (; ndex > 0; A->elemPtr[ndex] = A->elemPtr[ndex-1], --ndex) {} A->elemPtr[ndex] = data;
			A->count++;
			retVal = TRUE;
		}
	}
	return retVal;
}

void displayList(ArrayList D, Boolean flag) {
	(flag == 1) ? printf("The list was updated!\n") : printf("No new changes were made!\n");
	int i;
	for (i = 0; i < D->count; printf("[%c] ", D->elemPtr[i]), ++i) {} printf("\n\n");
}

Boolean deleteInstance(char data, ArrayList R) {
	int ndex = 0, shift;
	Boolean retVal = FALSE;
	while (ndex < R->count) {
		if (R->elemPtr[ndex] == data) {
			for (shift = ndex; shift < R->count; R->elemPtr[shift] = R->elemPtr[shift+1], ++shift) {} R->count--;
			retVal = TRUE;
		} else {++ndex;}
	}
	return retVal;
}

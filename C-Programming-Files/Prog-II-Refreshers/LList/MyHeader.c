#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"

void insertFront (NodePtr *list, int item) {
	NodePtr temp = malloc(sizeof(NodeType));
	
	if (temp != NULL) {
		temp->data = item;
		temp->next = *list; //change address to header link
		*list = temp; //update the value of link to the address of temp
	}
	
	
}
void display (NodePtr list) {
	printf("{");
	
	while (list != NULL) {
		printf("%d", list->data);
		if (list->next != NULL) {
			printf(" -> ");
		}
		list = list->next;
	}
	printf("}\n");
}

int getSum (NodePtr list) {
	int sum = 0;
	
	while (list != NULL) {
		sum += (list->data);
		list = list->next;
	}
	
	printf("In function: %d\n", sum);
	return sum;
}
float getAverage (NodePtr list){
	float ave = 0;
	int ctr = 0;
	
	while (list != NULL){
		ave += (list->data);
		list = list->next;
		ctr++;
	}
	ave /= ctr;
	printf("In Function: %.2f\n", ave);
	return ave;
}
int countFactors (NodePtr list, int value) {
	int factor = 0;
	
	while (list != NULL){
		if(list->data % value == 0){
			factor++;
		}
		list = list->next;
	}
	return factor;
}
void doubleOddNumbers (NodePtr list) {
	
	while (list != NULL) {
		if (list->data % 2 != 0) {
			list->data *= 2;
		}
		list = list->next;
	}
	
}

NodePtr getAllEven(NodePtr list) {
	NodePtr even = malloc(sizeof(NodeType));
	
	while (list != NULL){
		if(list->data % 2 == 0){
			even->data = list->data;
			printf("%d", even->data);
			even = even->next;
		}
		list = list->next;
	}
}


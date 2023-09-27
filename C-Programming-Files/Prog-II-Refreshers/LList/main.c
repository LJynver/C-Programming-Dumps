#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"

int main() {
	
	NodePtr myList = NULL;
	
	display(myList);
	
	insertFront(&myList, 1);
	display(myList);
	insertFront(&myList, 2);
	display(myList);
	insertFront(&myList, 3);
	display(myList);
	insertFront(&myList, 4);
	display(myList);
	insertFront(&myList, 5);
	display(myList);
	insertFront(&myList, 69);
	display(myList);
	insertFront(&myList, 7);
	display(myList);
	
	printf("\n");
	printf("In main: %d\n", getSum(myList));
	printf("\n");
	
	printf("In main: %.2f\n", getAverage(myList));
	printf("\n");
	
	printf("In main: %d\n", countFactors(myList, 2));
	printf("\n");
	
	printf("All even numbers: "); getAllEven(myList);
	printf("\n\n");
	
	doubleOddNumbers (myList);
	display(myList); printf("\n");
	
	
	
	return 0;
}

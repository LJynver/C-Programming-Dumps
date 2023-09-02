#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node {
	int arr[SIZE], count;
}ArrayList;

/*************** enum definition *****************************/
typedef enum {FALSE, TRUE} Bool;
/*** enum is short for enumeration ***************************
******* kinda like structs **********************************/
Bool findInt(ArrayList L, int x);
/** return true if x is in the given array, false if nope **/

int main () {
	
	ArrayList main = {{1,2,3,4,5,6}, 6};
	Bool check = findInt(main, 3);
	(check == 1) ? printf("We found it!") : printf("Looks like it is not here!") ;
	
	return 0;
}

Bool findInt(ArrayList L, int x) {
	Bool check;
	int i;
	for (i = 0; i < L.count && L.arr[i] != x; ++i) {}
	(i == L.count) ? (check = FALSE) : (check = TRUE);
	return check;
}

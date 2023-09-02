#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node {
	int arr[SIZE], count;
}ArrayList;

/*************** enum definition *****************************/
typedef enum {FALSE, TRUE} Boolean;
/*** enum is short for enumeration ***************************
******* kinda like structs **********************************/
Boolean findInt(ArrayList *L, int data);
Boolean findInsertSorted(ArrayList *L, int data);
/** return true if x is in the given array, false if nope **/

int main () {
	
	ArrayList main = {{1,2,3,4,5,6}, 6};
	Boolean check = findInsertSorted(&main, 10); 
	(check == 1) ? printf("No data was found!\nNew data was inserted!") : printf("Gothca!") ;
	
	return 0;
}

//Bool findInt(ArrayList L, int data) {
//	//Previously there was a check variable with Bool na enum type
//	int ndx;
//	for (ndx = 0; ndx < L.count && L.arr[ndx] != data; ++ndx) {}
//	return (ndx == L.count)? FALSE : TRUE; //one line ternary return
//}rn flag;
//}

Boolean findIntInsert(ArrayList *L, int data) {
	Boolean retVal;
	if (L->count < SIZE) {
		int ndx;
		for (ndx = 0; ndx < L->count && L->arr[ndx] != data; ++ndx) {}
		(ndx == L->count) ? (retVal = TRUE), L->arr[ndx] = data: (retVal = FALSE);
		++L->count;
	}
	return retVal;
}

Boolean findInsertSorted(ArrayList *L, int data) {
	Boolean retVal;
	if (L->count < SIZE) {
		int ctr;
		for (ctr = 0; ctr < L->count && L->arr[ctr] != data; ++ctr) {}
		if (ctr == L->count) {
			for (; ctr > 0 && L->arr[ctr-1] > data; L->arr[ctr] = L->arr[ctr-1], --ctr) {}
			L->arr[ctr] = data;
			L->count++;
			retVal = TRUE;
		} else {
			retVal = FALSE;
		}
	}
	return retVal;
}

//ArrayList *L= (ArrayList*)calloc(1, sizeof(ArrayList));
//L->arr[5] = {1,2,3,4,5};

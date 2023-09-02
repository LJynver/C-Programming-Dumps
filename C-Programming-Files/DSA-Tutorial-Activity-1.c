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
Bool findInt(ArrayList L, int data);
/** return true if x is in the given array, false if nope **/

int main () {
	
	ArrayList main = {{1,2,3,4,5,6}, 6};
	Bool check = findInt(main, 9);
	(check == 1) ? printf("We found it!") : printf("Looks like it is not here!") ;
	
	return 0;
}

Bool findInt(ArrayList L, int data) {
	//Previously there was a check variable with Bool na enum type
	int ndx;
	for (ndx = 0; ndx < L.count && L.arr[ndx] != data; ++ndx) {}
	return (ndx == L.count)? FALSE : TRUE; //one line ternary return
}

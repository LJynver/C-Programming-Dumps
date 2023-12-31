#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************/
/***** DO NOT RUN THIS C FILE ******/
/***********************************/
/**** THIS IS JUST A TEMPLATE ******/
/***********************************/
/****** USE IT FOR REFERENCE *******/
/***********************************/


/******** ITEM 1 DEFINTION *********/

typedef struct {
	char FN[24], LN[16], MI;
}nametype;

typedef struct {
	char ID[10];
	nametype name;
	char course[8];
	int yrLevel;
}studRec;

#define VH_MAX 0XFF

typedef struct {
	studRec stud;
	int link; //-1 if there is no next node
}CBNode;

typedef struct {
	CBNode heap[VH_MAX];
	int avail;
}*Vheap;

typedef int CursorList;
/** CursorList is merely just an integer data type variable with a new alias **/

#define MAX 0XA

typedef struct node {
	studRec data[MAX];
	int studCtr; //elem counter
}*ArrayList;

int insertClist(Vheap virtheap, ArrayList arrlist, CursorList *clist);

/***** MY FUNCTION DEFINITION ******/

int insertClist(Vheap virtheap, ArrayList arrlist, CursorList *clist)
{
	int retval = 0;
	CursorList * trav, temp;
	while (arrlist->studCtr > 0 && virtheap->avail != -1) {
		for (trav = clist; *trav != -1 && strcmp(virtheap->heap[*trav].stud.ID, arrlist->data[arrlist->studCtr-1].ID) < 0; trav = &virtheap->heap[*trav].link) {}
		if (*trav == -1 || strcmp(virtheap->heap[*trav].stud.ID, arrlist->data[arrlist->studCtr-1].ID) != 0) {
			temp = virtheap->avail;
			virtheap->avail = virtheap->heap[temp].link;
			
			virtheap->heap[temp].stud = arrlist->data[arrlist->studCtr-1];
			virtheap->heap[temp].link = *trav;
			*trav = temp;
			
			retval++;
			arrlist->studCtr--;
			//Although this would work but it will operate as if I am deleting the arrlist
			//Which is not supposed to happen

		}
	}
	
	return retval;
}

/****** POST-EXAM DEFINITION 1 *****/

int insertClist(Vheap virtheap, ArrayList arrlist, CursorList *clist)
{
	int retval = 0, ndx;
	CursorList * trav, temp;

	if (arrlist->studCtr <= MAX) { //another case if ever the virtual heap is smaller than the arraylist
		for (ndx = arrlist->studCtr-1; ndx >= 0 && virtheap->avail != -1; --ndx) {
			for (trav = clist; *trav != -1 && strcmp(virtheap->heap[*trav].stud.ID, arrlist->data[ndx].ID) < 0 ; trav = &virtheap->heap[*trav].link) {}

			if (*trav == -1 || strcmp(virtheap->heap[*trav].stud.ID, arrlist->data[ndx].ID) != 0) {
				temp = virtheap->avail;
				virtheap->avail = virtheap->heap[temp].link;

				virtheap->heap[temp].stud = arrlist->data[ndx];
				virtheap->heap[temp].link = *trav;
				*trav = temp;

				retval++;
			}
		}
	}
	
	return retval;
}

/****** POST-EXAM DEFINITION 2 *****/

int insertClist(Vheap virtheap, ArrayList arrlist, CursorList *clist)
{
	int retval = 0, ndx;
	CursorList * trav, temp;

	
	
	return retval;
}

/********* END OF ITEM 1 ***********/

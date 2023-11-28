#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define MAX 0XA

typedef struct node {
	studRec data[MAX];
	int studCtr; //elem counter
}*ArrayList;

int insertClist(Vheap virtheap, ArrayList arrlist, CursorList *clist);

int main () {
	
	
	
	return 0;
}

int insertClist(Vheap virtheap, ArrayList arrlist, CursorList *clist)
{
	int retval = 0;
	CursorList * trav, temp;
	while (arrlist->studCtr > 0 && virtheap->avail != -1) {
		for (trav = head; *trav != -1 && strcmp(virtheap->heap[*trav].stud.ID, arrlist->data[arrlist->studCtr-1].ID) < 0) {}
		if (*trav == -1 || strcmp(virtheap->heap[*trav].stud.ID, arrlist->data[arrlist->studCtr-1].ID) != 0) {
			temp = virtheap->avail;
			virtheap->avail = virtheap->heap[temp].link;
			
			virtheap->heap[temp].stud = arrlist->data[arrlist->studCtr-1];
			virtheap->heap[temp].link = *trav;
			*trav = temp;
			
			retVal++;
			arrlist->studCtr--;
			
		}
	}
	
	return retval;
}

#include <stdio.h>
#define SIZE 6
typedef struct nodes {
	char elem;
	int link;
}nodeType;

typedef struct vheap {
	nodeType Nodes[SIZE];
	int avail;
}VirtualHeap;

typedef int CLIST;

int initHeap(VirtualHeap* V);
void insertSorted(CLIST *C, VirtualHeap *V, char data);
int allocSpace(VirtualHeap *V);
void displayList(CLIST C, VirtualHeap V);

int main () {
	
	VirtualHeap VH;
	CLIST L = initHeap(&VH);
	insertSorted(&L, &VH, 'A');
	insertSorted(&L, &VH, 'Z');
	insertSorted(&L, &VH, 'F');
	insertSorted(&L, &VH, 'B');
	insertSorted(&L, &VH, 'J');
	
	
	displayList(L, VH);
	
	return 0;
}

int initHeap(VirtualHeap* V) {
	int i;
	for (i=0; i<SIZE; ++i) {
		V->Nodes[i].link = i-1;
	}
	V->avail = i-1;
	return -1;
}

void insertSorted(CLIST *C, VirtualHeap *V, char data) {
	CLIST *trav = C;
	for (; *trav != -1 && V->Nodes[*trav].elem < data; trav = &V->Nodes[*trav].link) {}
	int ndx = allocSpace(V);
	if (ndx != -1) {
		V->Nodes[ndx].elem = data;
		V->Nodes[ndx].link = *trav;
		*trav = ndx;
	}
}

int allocSpace(VirtualHeap *V) {
	int ndx = V->avail;
	if (ndx != -1) {
		V->avail = V->Nodes[ndx].link;	
	}
	return ndx;
}

void displayList(CLIST C, VirtualHeap V) {
	for (; C != -1; C = V.Nodes[C].link) {
		printf("-%c--", V.Nodes[C].elem);
	}
}

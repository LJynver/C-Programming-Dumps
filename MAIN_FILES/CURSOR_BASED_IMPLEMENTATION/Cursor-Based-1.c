#include <stdio.h>
#define SIZE 5

typedef struct nodes {
	char data;
	int link;
}node_type;

typedef struct vHeap {
	node_type nodes[SIZE];
	int avail;
}VirtualHeap;

typedef int List;

int initVHeap(VirtualHeap* VH);
void insertFirst(List *L, char data, VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int ndx);
void removeElement(List *L, char data, VirtualHeap *VH);

int main () {
	
	VirtualHeap VH;
	List L = initVHeap(&VH);
	insertFirst(&L, 'A', &VH);
	insertFirst(&L, 'B', &VH);
	insertFirst(&L, 'D', &VH);
	insertFirst(&L, 'C', &VH);
	insertFirst(&L, 'F', &VH);
	insertFirst(&L, 'Z', &VH);
	removeElement(&L, 'B', &VH);
	
	return 0;
}

int initVHeap(VirtualHeap* VH) {
	int ndx;
	for (ndx = 0; ndx < SIZE; ++ndx) {
		VH->nodes[ndx].data = '\0';
		VH->nodes[ndx].link = ndx-1;
	}
	VH->avail = ndx-1;
	return -1;
}

//int initVHeap(VirtualHeap* VH) {
//    int ndx;
//    for (ndx = 0; ndx < SIZE; ++ndx) {
//      if (ndx < SIZE-1) {
//        VH->nodes[ndx].link = ndx+1;
//      } else {
//        VH->nodes[ndx].link = -1;
//      }
//    }
//    VH->avail = 0;
//    return -1;
//}

void insertFirst(List *L, char data, VirtualHeap *VH) {
	if (VH->avail > -1 && VH->avail < SIZE) {
		int pos = allocSpace(VH);
		VH->nodes[pos].data = data;
		VH->avail = VH->nodes[pos].link;
		VH->nodes[pos].link = *L;
		*L = pos;
	} else {
		printf("There is not enough space here!");
	}
}

int allocSpace(VirtualHeap *VH) {
	int retVal = VH->avail;
	return retVal;
}

void removeElement(List *L, char data, VirtualHeap *VH) {
	int ndx;
	// for (ndx = *L; ) {}
}

void deallocSpace(VirtualHeap *VH, int ndx) {
	VH->nodes[ndx].data = '\0';
	VH->nodes[ndx].link = VH->avail;
	VH->avail = ndx;
}
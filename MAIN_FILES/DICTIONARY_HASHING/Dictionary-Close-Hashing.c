#include <stdio.h>

//close hashing attempt

#define EMPTY '0'
#define DELETED '!'

#define MAX_ARRAY 26
#define PRIME_SET MAX_ARRAY/2

typedef struct nodes {
    char data;
    int link;
} Nodes;

typedef struct list {
    Nodes Dictionary[MAX_ARRAY];
    int avail;
} VHeap;

VHeap initDictionary();
int Hashing(char data);
void insertDictionary(VHeap *L, char data);
void deleteDictionary(VHeap *L, char data);
int allocSpace(VHeap *L);
void displayDictionary(VHeap D);
int isMember(VHeap M, int pos, char data);
void deAllocSpace(VHeap *L, int pos);

typedef int Start;

int main () {

    VHeap List = initDictionary();

    printf("\nInitialized...\n\n");
    displayDictionary(List);
    printf("\n\n");

    insertDictionary(&List, 'A');
    insertDictionary(&List, 'A');
    insertDictionary(&List, 'B');
    insertDictionary(&List, 'b');
    insertDictionary(&List, 'Z');
    insertDictionary(&List, 'O');
    insertDictionary(&List, 'F');
    insertDictionary(&List, 'L');
    insertDictionary(&List, 'N');

    //format for the display [index, data]
    //shows the arrow if there are synonyms
    // '!' is a sign the data is deleted

    displayDictionary(List);
    printf("\n\n");

    deleteDictionary(&List, 'A');
    deleteDictionary(&List, 'A');

    displayDictionary(List);

    return 0;
}

VHeap initDictionary() {
    VHeap newDict;
    int ndx;
    for (ndx = 0; ndx < PRIME_SET; ++ndx) {
        newDict.Dictionary[ndx].data = EMPTY;
        newDict.Dictionary[ndx].link = -1;
    }
    newDict.avail = ndx;
    for (; ndx < MAX_ARRAY; ++ndx) {
        newDict.Dictionary[ndx].data = EMPTY;

        // if (ndx < MAX_ARRAY - 1) {
        //     newDict.Dictionary[ndx].link = ndx + 1;
        // } else {
        //     newDict.Dictionary[ndx].link = DELETED;
        // }

        newDict.Dictionary[ndx].link = (ndx < MAX_ARRAY - 1) ? ndx + 1 : -1;
        //shorthand

    }
    return newDict;
}

int Hashing(char data) {
    return data % PRIME_SET;
}

void insertDictionary(VHeap *L, char data) {
    int pos = Hashing(data);

    if (L->Dictionary[pos].data == EMPTY || L->Dictionary[pos].data == DELETED) {
        L->Dictionary[pos].data = data;
    } else {
        int synPos = allocSpace(L);
        if (synPos != -1) {
            L->Dictionary[synPos].data = data;
            L->Dictionary[synPos].link = L->Dictionary[pos].link;
            L->Dictionary[pos].link = synPos;
        } else {
            printf("\nMemory exceeded limit\n");
        }
    }
    
}

int allocSpace(VHeap *L) {
    int pos = L->avail;
    if (pos != -1) {
        L->avail = L->Dictionary[pos].link;
    }
    return pos;
}

void displayDictionary(VHeap D) {
    int ndx, synDx;
    printf("-- PRIME --- \t --- SYNONYM ---\n\n");
    for (ndx = 0; ndx < PRIME_SET; ++ndx) {
        printf("[%d, %c]", ndx, D.Dictionary[ndx].data);

        if (D.Dictionary[ndx].link != -1) {
            printf("\t -------> \t");
            for (synDx = D.Dictionary[ndx].link; synDx != -1 ; synDx = D.Dictionary[synDx].link) {
                (D.Dictionary[synDx].link != -1) ? printf("[%d, %c] -> ", synDx, D.Dictionary[synDx].data) : printf("[%d, %c]", synDx, D.Dictionary[synDx].data);
            }
        }

        printf("\n");

    }
}

int isMember(VHeap M, int pos, char data) { //returns the index
    int retVal = -1;
    for (; pos != -1 && M.Dictionary[pos].data != data; pos = M.Dictionary[pos].link) {}
    if ( pos != -1 ) {
        retVal = pos;
    }
    return retVal;
}

void deleteDictionary(VHeap *L, char data) {
    int pos = Hashing(data);

    int delPos = isMember(*L, pos, data);

    if (delPos != -1) {
        L->Dictionary[delPos].data = DELETED;
    }
}
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//attempt to do dictionary cursor-based implementation
//closed hashing

#define MAX_SIZE 50
#define PRIME_SET (MAX_SIZE/5)

#define EMPTY 0
#define DELETED -1 //empty data or no link at all

typedef char String[30];

typedef struct studrec {
    int year, studID;
    String fname, lname, program;
    int courses[10];
} StudRec;

typedef struct node {
    StudRec profile;
    int next;
} Node;

typedef struct vheap {
    Node studList[MAX_SIZE];
    int avail;
} Vheap;

Vheap initDictionary();
int hash(int data);
void insert(Vheap *Dict, StudRec data);
void delete(Vheap *Dict, int id);
int isMember(Vheap Dict, int ID);
void display(Vheap Dict);

int main () {

    Vheap main = initDictionary();

    StudRec A = {2, 22103650, "Lyan", "Jover", "BSIT", {2101, 2102, 2103, 2105, 2106, -1}};
    StudRec B = {2, 22207747, "Maria", "Mary", "BSCS", {2101, 2102, 2103, 2104, 2105, 2106,-1}};
    StudRec C = {1, 22309987, "Cindy", "Lepatan", "BSCS", {2101, 2102, 2103, 2104, 2105, 2106,-1}};

    insert(&main, A);
    insert(&main, B);
    insert(&main, C);

    display(main);

    return 0;
}

Vheap initDictionary() {
    Vheap start;
    int ndx;
    for (ndx = 0; ndx < MAX_SIZE; ndx++) {
        start.studList[ndx].profile.studID = EMPTY;
        start.studList[ndx].profile.courses[0] = -1;
        start.studList[ndx].next = (ndx < PRIME_SET) ? -1 : ndx+1;
    }
    start.studList[ndx-1].next = -1;
    start.avail = PRIME_SET;
    return start;
}

int hash(int data) {
    return (data % PRIME_SET);
}

void insert(Vheap *Dict, StudRec data) {
    int pos = hash(data.studID);

    if (Dict->studList[pos].profile.studID == EMPTY) {
        Dict->studList[pos].profile = data;
    } else {
        int *trav;
        for (trav = &Dict->studList[pos].next; *trav != -1 && Dict->studList[*trav].profile.studID != data.studID; trav = &Dict->studList[*trav].next) {}

        if (*trav == -1) {
            int adx = Dict->avail;
            if (adx != -1) {
                Dict->avail = Dict->studList[adx].next;
                Dict->studList[adx].profile = data;
                Dict->studList[adx].next = *trav;
                *trav = adx;
            } else {
                printf("\nNOT ENOUGH SPACE!\n");
            }
            
        }
    }

}

void display(Vheap Dict) {
    int ndx, cdx, sdx; //ndx is actual index, cdx is courses index, sdx is synonyms index
    for (ndx = 0; ndx < PRIME_SET; ++ndx) {
        printf("[Block: %c]\n", ndx+65);

        if (Dict.studList[ndx].profile.studID != EMPTY) {

            printf("\n[%d]\nFirst Name: %s\nLast Name: %s\nStudentID: %d\nProgram: %s\nCourses: ", ndx, Dict.studList[ndx].profile.fname, Dict.studList[ndx].profile.lname, Dict.studList[ndx].profile.studID, Dict.studList[ndx].profile.program);

            if (Dict.studList[ndx].profile.courses[0] != -1) {
                for (cdx = 0; Dict.studList[ndx].profile.courses[cdx] != -1; ++cdx) {
                    printf("%d ", Dict.studList[ndx].profile.courses[cdx]);
                }
            }

            if (Dict.studList[ndx].next != -1) { //checks if there are synonyms
                printf("\n\n");
                for (sdx = Dict.studList[ndx].next; sdx != -1; sdx = Dict.studList[sdx].next) {

                    printf("\n[%d]\nFirst Name: %s\nLast Name: %s\nStudentID: %d\nProgram: %s\nCourses: ", sdx, Dict.studList[sdx].profile.fname, Dict.studList[sdx].profile.lname, Dict.studList[sdx].profile.studID, Dict.studList[sdx].profile.program);

                    if (Dict.studList[sdx].profile.courses[0] != -1) {
                        for (cdx = 0; Dict.studList[sdx].profile.courses[cdx] != -1; ++cdx) {
                            printf("%d ", Dict.studList[sdx].profile.courses[cdx]);
                        }
                    }

                }
            }
        
        }

        printf("\n\n---------------\n\n");

    }
}

int isMember(Vheap Dict, int ID) {
    int pos = hash(ID);

    for (; pos != -1 && Dict.studList[pos].profile.studID != ID; pos = Dict.studList[pos].next) {}

    return pos;
}

void delete(Vheap *Dict, int id) {
    int pos = hash(id);
    if (Dict->studList[pos].profile.studID == id) {
        Dict->studList[pos].profile.studID = DELETED;
    } else {
        int *trav;
        for (trav = &Dict->studList[pos].next; *trav != -1 && Dict->studList[*trav].profile.studID != id; trav = &Dict->studList[*trav].next) {}

        if (*trav != -1) {
            int dpx = *trav;
            *trav = Dict->studList[dpx].next;
            Dict->studList[dpx].profile.studID = DELETED;
            Dict->studList[dpx].next = Dict->avail;
            Dict->avail = dpx;
        } else {
            printf("\nNOWHERE TO BE FOUND!\n");
        }
    }
}
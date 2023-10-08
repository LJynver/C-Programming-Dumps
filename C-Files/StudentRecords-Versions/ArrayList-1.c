#include <stdio.h>

#define MAX 10

typedef char String[30];

typedef struct studRec {
    int year;
    String fname, lname, program;
    int courses[10];
} StudRec;

typedef struct list {
    StudRec studRecList[MAX];
    int count;
} StudList;

StudList initList();
void display(StudList D);
void push(StudList *P, StudRec temp);
void pop(StudList *P);

int main () {

    StudList mainList = initList();

    StudRec A = {2, "Lyan", "Jover", "BSIT", {2101, 2102, 2103, 2105, 2106, -1}};
    StudRec B = {2, "John", "Doe", "BSCS", {2101, 2102, 2103, 2104, 2105, 2106, -1}};
    StudRec C = {2, "Julianne", "Mary", "BSIS", {1201, 2105, 2106, -1}};

    push(&mainList, A);
    push(&mainList, B);
    push(&mainList, C);
    
    printf("Count: %d", mainList.count);

    display(mainList);

    return 0;
}

StudList initList() {
    StudList start = {.count = 0};
    return start;
}

void push(StudList *P, StudRec temp) {
    int ndx = P->count;
    if (ndx != MAX) {
        P->studRecList[ndx] = temp;
        P->count++;
    } else {
        printf("\nStack is full!\n");
    }
}

void pop(StudList *P) {
    P->count--;
}

void display(StudList D) {
    StudList temp = {.count = 0};
    D.count--;
    for (; D.count > -1 ; temp.count++) {
        
    }
}
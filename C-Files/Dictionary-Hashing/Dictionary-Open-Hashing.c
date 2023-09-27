#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

typedef struct nodes {
    int data;
    struct nodes *next;
} *List;

typedef List Dictionary[SIZE];



int main () {

    Dictionary main;

    return 0;
}
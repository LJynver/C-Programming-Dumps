#include <stdio.h>
#include "headers/v1_adjlist.h"
#include "headers/v1_adjlist.c"

int main () {

    Dictionary mainlist;
    initDictionary(mainlist);

    printDictionary(mainlist);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 8

typedef struct node {
    char *ptr;
    int count;
}List;

List init();
void insertFrontUnique(char data, List *main);
void removeInstance(char data, List *main);

int main () {
    
    List main = init();
    insertFrontUnique('A', &main);
    insertFrontUnique('A', &main);
    insertFrontUnique('B', &main);
    insertFrontUnique('D', &main);
    insertFrontUnique('F', &main);
    insertFrontUnique('G', &main);
    insertFrontUnique('F', &main);
    insertFrontUnique('Y', &main);
    insertFrontUnique('Z', &main);
    removeInstance('B', &main);
    
    return 0;
}

List init() {
    List start = {
        .ptr = (char*)calloc(MAX, 1),
        .count = -1
    };
    return start;
}

void insertFrontUnique(char data, List *main) {
    int i;
    for (i = 0; i <= main->count && main->ptr[i] != data; ++i) {}
    if (i < MAX && i > main->count) {
        main->ptr[++main->count] = data;
    }
}

void removeInstance(char data, List *main) {
    int i, j;
    for (i = 0; i < main->count; ++i) {
        j = i;
        if (main->ptr[i] == data) {
            for (; j < main->count; main->ptr[j] = main->ptr[j+1], ++j) {}
            main->ptr[main->count--] = '\0';
        }
    }
}

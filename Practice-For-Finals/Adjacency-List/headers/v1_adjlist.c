#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "v1_adjlist.h"

void initDictionary(Dictionary main)
{
    int i;
    for (i = 0; i < SIZE; ++i) {
        // main[i]->data = 65 + i;
        strcpy(main->data, "\0");
        main[i].next = NULL;
    }
}

void printDictionary(Dictionary main)
{
    int i;
    Node *trav;
    for (i = 0; i < SIZE; ++i) {
        trav = main[i].next;
        printf("%s ", main[i].data);
        while (trav != NULL) {
            printf("-> %c ", trav->data);
            trav = trav->next;
        }
        printf("\n");
    }
}

int hashIndex(char data)
{
    return (data - 65) % SIZE;
}

void insertDictionary(Dictionary main, String input)
{
    int ndx = hashIndex(input[0]);
    Node **trav = NULL;
    if (main[ndx].data[0] != '\0') {
        strcpy(main[ndx].data, input);
    } else {
        for (trav = &main->next; *trav != NULL && strcmp((*trav)->data, input) != 0; trav = &(*trav)->next) {}
    }
}
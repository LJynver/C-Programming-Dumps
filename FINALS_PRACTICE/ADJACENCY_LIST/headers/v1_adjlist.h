#ifndef ADJ_LIST_V1
#define ADJ_LIST_V1

#define SIZE 5

typedef char String[30];

typedef struct node {
    String data;
    struct node *next;
}Node;

typedef Node Dictionary[SIZE];

void initDictionary(Dictionary main);
void printDictionary(Dictionary main);
int hashIndex(char data);
void insertDictionary(Dictionary main, String input);

#endif
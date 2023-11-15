#ifndef DICT_V1
#define DICT_V1

//Preprocessors
#define SIZE 20
#define PRIME_SIZE ((SIZE * 80) / 100)

//Definitions
typedef struct vnode {
	char data;
	int next;	
}VNode;

typedef struct dict {
	VNode nodes[SIZE];
	int avail;
}Dict;

//Function-Prototype
Dict init();
int hash(int num);
void insertDict(Dict* main, int data);

#endif
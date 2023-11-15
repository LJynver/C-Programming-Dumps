#include <stdio.h>
#include "v1.h"

Dict init() {
	Dict start;
	int i;
	for (i = 0; i < PRIME_SIZE; ++i) {
		start.nodes[i].data = '\0';
		start.nodes[i].next = i-1;
	}
	for (; i < SIZE; ++i) {
		start.nodes[i].next = -99;
	}
	return start;
}

int hash(int num) {
	return num % PRIME_SIZE;
}

void insertDict(Dict* main, int data) {
	int hdex = hash(data);
	
}
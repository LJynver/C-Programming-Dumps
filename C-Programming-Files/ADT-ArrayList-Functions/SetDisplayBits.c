#include <stdio.h>
#include <stdlib.h>

typedef unsigned char SET;

void displayBitPattern(SET A);
void displaySetElement(SET A);

int main () {
	
	SET a = 26;
	displayBitPattern(a);

	return 0;
}

void displayBitPattern(SET A) {
	SET mask;
	
	for (mask = 1 << (sizeof(SET) * 8)-1; mask > 0; mask >>= 1) {
		printf("%d", ((mask & A) != 0) ? 1 : 0);
	}
}

void displaySetElement(SET A) {
	
}

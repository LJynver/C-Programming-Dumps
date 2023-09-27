#include <stdio.h>

int main () {
	
	int num = 12, bits = 16, i;
	
	for (i = bits-1; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
		if (i % 4 == 0) {
			printf(" ");
		}
	}
	
	return 0;
}
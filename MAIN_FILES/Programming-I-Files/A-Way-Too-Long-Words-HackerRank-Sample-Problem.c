#include <stdio.h>

int main () {
	
	int entries, i;
	do {
		scanf("%d", &entries);
	} while (!(entries>=1 && entries<=100));
	printf("\n");
	
	char word[100];
	while (entries > 0) {
		scanf("%s", word);
		for (i=0; *(word+i) != '\0'; i++) {}
		if (i>10) {
			printf("%c%d%c\n", *(word+0), i-2, *(word+i-1));
		}
		entries--;
	}
	
	return 0;
}
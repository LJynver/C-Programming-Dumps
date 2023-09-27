#include <stdio.h>
#define MAX 10
int main () {
	
	char code[MAX];
	printf("The Coded Message is: "); scanf("%s", &code);
	char first[] = {'A','B','C','D','I'};
	char second[] = {'N','O','P','Q','E'};
	
	int i, f, s;
	for (i=0; *(code+i) != '\0'; i++) {
		for (f=0; *(first+i) < sizeof(first); f++) {
			if (*(code+i) == *(first+f)) {
				char temp = *(code+i);
				*(code+i) = *(first+f);
				*(first+f) = temp;
			}
		}
		for (s=0; *(second+i) < sizeof(second); s++) {
			if (*(code+i) == *(second+s)) {
				char temp = *(code+i);
				*(code+i) = *(second+s);
				*(second+s) = temp;
			}
		}
	}
	
	printf("%s", code);
	
	return 0;
}
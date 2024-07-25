#include <stdio.h>
#include <ctype.h>

int main () {
	
	char word[50];
	scanf("%s", word);
	int csnt = 0;
	int vwl = 0;
	
	int i;
	for (i = 0; *(word+i) != '\0'; i++) {
		*(word+i) = tolower(*(word+i));
		if (*(word+i) == 'a' || *(word+i) == 'e' || *(word+i) == 'i' || *(word+i) == 'o' || *(word+i) == 'u') {
			vwl++;
		} else {
			csnt++;
		}
	}
	
	printf("Number of consonants: %d\n", csnt);
	printf("Number of vowels: %d", vwl);
	
	return 0;
}
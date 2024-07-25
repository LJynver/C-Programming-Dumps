#include <stdio.h>

//standard version

void update(int *a,int *b) {
	int val1 = *a, val2 = *b;
	*a = val1 + val2;
	*b = val1 - val2;
	if (*b < 0) {
		*b *= -1;
	}
	
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
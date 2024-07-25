#include <stdio.h>
#include <stdlib.h>

/*This version makes use of the stdlib library
Specifically, we will use the abs function*/

void update(int *a,int *b) {
	int val1 = *a, val2 = *b;
	*a = val1 + val2;
	*b = abs(val1 - val2);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
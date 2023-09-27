#include <stdio.h>

void main ()
{
    int n, count = 0, digit;
    printf("Enter an integer: ");
    scanf("%d", &n);
    while (n!=0) {
		printf("%d\n", n%10);
		n/=10;
		count++;
    }
    printf("The inputted integer had %d digits.", count);
}
#include <stdio.h>

int main()
{
    char c1, c2;
    int d;
    
    printf("Enter first character: ");
    scanf(" %c", &c1);
    printf("\nThe first character: %c has a value of %d", c1, c1);
    
    printf("\nEnter second character: ");
    scanf(" %c", &c2);
    printf("\nThe second character: %c has a value of %d", c2, c2);
    
    d = c1 - c2;
    
    printf("\n\nThe difference between the two characters is %d", d);

    return 0;
}


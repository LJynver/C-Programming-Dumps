#include <stdio.h>

int main() {
    
    int i1, n2, sum  = 0;
    
    printf("Enter a 6-digit number: ");
    scanf("%d", &i1);
    
    while (i1 > 0) {
        
        if (n2 % 2 != 0) {
            sum = sum + n2;
        }
        i1 = (i1 - n2)/10;
    }
    
    printf("The sum of the odd integers are: %d", sum);
    
    return 0;
}

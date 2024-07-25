#include <stdio.h>

int main() {
    
    while (1) {
        const int refyear = 1993;
        int byear, diffcon;
        
        printf("Input your birthyear: ");
        scanf("%d", &byear);
        
        diffcon = byear - refyear;
        
        if (diffcon < 15) {
            printf("\nINVALID INPUT! Try again\n\n");
        } else if (diffcon >= 15) {
            printf("\nAge difference: %d", diffcon);
            break;
        }
    }
    
    return 0;
}


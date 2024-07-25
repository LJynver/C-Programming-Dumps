#include <stdio.h>

int main() {
    
    int opt;
    char a, b, result_1, result_2;
    
    opt = 0;
    
    printf("1. Upper to Lower");
    printf("\n2. Lower to Upper");
    
    printf("\nChoose option number: ");
    scanf(" %d", &opt);
    
    switch (opt)
    {
        case 1: {
            printf("Type in an uppercase letter: ");
            scanf(" %c", &a);
            result_1 = a + 32;
            printf(" %c", result_1);
        } break;
        
        case 2: {
            printf("Type in a lowercase letter: ");
            scanf(" %c", &b);
            result_2 = b - 32;
            printf(" %c", result_2);
        } break; 
        
        default: {
            printf("Invalid!");
        }
    }
    
    return 0;
}

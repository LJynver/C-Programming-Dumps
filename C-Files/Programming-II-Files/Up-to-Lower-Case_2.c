#include <stdio.h>

char lowerCase(char let);

int main() {
    
    char input_Letter;
    
    printf("Type a string: ");
    scanf("%s", &input_Letter);
    printf("\nThe lowercase of letter %c is: %c", input_Letter, lowerCase(input_Letter));
    
    return 0;
}

char lowerCase(char let) {
    return let + 32;
    
}

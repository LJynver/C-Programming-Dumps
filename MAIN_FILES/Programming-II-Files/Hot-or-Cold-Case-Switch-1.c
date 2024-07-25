#include <stdio.h>

int main() {
    
    int i;
    
    float ref_temp = 100.00;
    float temp;
    
    printf("Was it Hot or Cold?\n");
    printf("What do you think was the temperature?");
    
    for (i = 1; i <= 10; i++) { 
        printf("\n[guess %d] Try to guess: ", i);
        scanf("%f", &temp);
        
        if (temp > ref_temp) {
            printf("\n***Go lower! It is hot!***\n");
        } else if (temp < ref_temp) {
            printf("\n***Go higher! It is cold!***\n");
        } else if (temp == ref_temp) {
            printf("\n***That is correct!***\nYou guessed the boiling point of water!");
            break;
        } else {
            printf("What was that? Try again please!\n");
        }
    }

	printf("\n\nNice try!");
	
    return 0;
}

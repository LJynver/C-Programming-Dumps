#include <stdio.h>

int main () {
    int num, reverse = 0, remainder;
    printf("Enter a number: ");
    scanf("%d", num);
    
    //temporary storing of the input
    int temp = num;
    
    //while loop to form a new number
    while (num != 0) {
    	remainder = num%10;
        reverse = reverse*10+remainder;
        num/=10;
    }
    
    //check if the original is equal to reverse
    if (reverse == temp) {
        printf("%d is a Palindrome", temp);
    } else {
        printf("%d is not a Palindrome", temp);
    }
    
    return 0;
}

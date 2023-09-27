#include <stdio.h>

int main() {
    int arr[100]; // array to store input values
    int n, i, smallest, second_smallest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // loop to read input values
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // find the smallest and second smallest values
    smallest = arr[0];
    second_smallest = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }
   
    // print the second smallest value
    printf("The second smallest value in the array is: %d\n", second_smallest);

    return 0;
}
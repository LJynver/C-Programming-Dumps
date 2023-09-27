#include <stdio.h>
#define N 5

void main () {
    int arr[N];
    int *ptrMax = arr, *ptrMin = arr;
    int max, min, i;
    int large = 0, small = 0;
    
    for (i = 0; i < N; i++) {
        printf("Enter the value for arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    //Start
    large = arr[0];
    small = arr[0];
    for (i = 1; i < N; i++) {
        if (*(arr+i) > large) {
//            ptrMax = (arr+i);
			large = *(arr+i);
        }
        if (*(arr+i) < small) {
//            ptrMin = (arr+i);
			small = *(arr+i);
        }
    }
//    printf("Largest Number: %d\nSmallest Number: %d", *ptrMax, *ptrMin);
    printf("Largest Number: %d\nSmallest Number: %d", large, small);
    //End
}
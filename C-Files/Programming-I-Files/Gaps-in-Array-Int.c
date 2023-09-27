#include <stdio.h>

int main (void) {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", arr+i);
    }
    
    printf("Gaps: ");
    for (int a = 0; a < 5; a++) {
        for (int b = a+1; b == a+1 && b < 5; b++) {
            if (arr[a]-arr[b] > 1 || arr[a]-arr[b] < -1) {
                int gaps = arr[a] + 1;
                while (gaps != arr[b]) {
                    printf("%d ", gaps);
                    gaps++;
                }
            }
        } 
    }
}
#include <stdio.h>

/*this makes use of the less efficient method
except we're using functions this time*/

void sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void display(int arr[], int size) {
    for (int a = 0; a < size; a++) {
        printf("%d ", arr[a]);
    }
}

int main () {
    int array[] = {21,34,56,72,3,6,7};
    int size = sizeof(array)/sizeof(int);
    
    display(array, size);
    printf("\n");
    sort(array, size);
    display(array, size);
    
    return 0;
}
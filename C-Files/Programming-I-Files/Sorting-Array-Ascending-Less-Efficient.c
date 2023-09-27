#include <stdio.h>

/*less efficient way
at least compares every element
per traversed element*/

int main () {
    int array[] = {21,34,56,72,3,6,7};
    int size = sizeof(array)/sizeof(int);
    
    //int i will serve as the nth iteration of the loop, traversing the entire array
    //int j will serve as the one who does the swapping work
    
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    //write a print statement here
    
    return 0;
}
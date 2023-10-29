#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

int main () {

    int nums[] = {1,3,5,6};
    int retVal = searchInsert(nums, 4, 10);

    printf("\nReturned: %d\n", retVal);

    return 0;
}

int searchInsert(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize-1, ndx = 0, retVal;

    while (low <= high) {
        ndx = (low + high)/2;
        if (nums[ndx] < target || nums[ndx] == target) {
            low = ndx+1;
            retVal = (nums[ndx] == target) ? ndx : low;
        } else {
            high = ndx-1;
        } 
    }
    return retVal;
}
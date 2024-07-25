#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target);

int main () {

    int nums[] = {1};

    printf("\nReturned: %d\n", searchInsert(nums, 1, 1));

    return 0;
}

int searchInsert(int* nums, int numsSize, int target) {

    int low = 0, high = numsSize-1, ndx = 0, retVal = 0;

    while (low <= high) {
        ndx = (low + high)/2;
        if (nums[ndx] >= target) {
            retVal = (nums[ndx] == target) ? ndx : ndx - 1;
            high = ndx - 1;
        } else {
            retVal = low = ndx + 1;
        }
    }

    return (retVal > 0) ? retVal : retVal+1;

}
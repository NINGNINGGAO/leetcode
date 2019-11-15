/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:37:17
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:40:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* sort(int* nums, int numsSize) {
    int i, j, temp;
    for (i = 0; i < numsSize -1; i++) {
        for (j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    return nums;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int i, j, k, h;
    int ptr_ra = -1;
    int newtarget;

    int** returnArray = (int**)malloc(sizeof(int*) * 17000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 17000);
    nums = sort(nums, numsSize);


    for (i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (j = i + 1; j < numsSize - 2; j++) {
            if (j > i +1 && nums[j] == nums[j - 1]) continue;
            k = j + 1;
            h = numsSize - 1;
            newtarget = target - nums[i] - nums[j];
            while (k < h) {
                if (nums[k] + nums[h] == newtarget) {
                    returnArray[++ptr_ra] = (int*)malloc(sizeof(int) * 4);
                    returnArray[ptr_ra][0] = nums[i];
                    returnArray[ptr_ra][1] = nums[j];
                    returnArray[ptr_ra][2] = nums[k];
                    returnArray[ptr_ra][3] = nums[h];
                    (*returnColumnSizes)[ptr_ra] = 4;
                    while (k < h && nums[k] == nums[k + 1]) k++;
                    while (k < h && nums[h] == nums[h - 1]) h--;
                    k++;
                    h--;
                } else if (nums[k] + nums[h] < newtarget) {
                    while (k < h && nums[k] == nums[k + 1]) k++;
                    k++;
                } else if (nums[k] + nums[h] > newtarget) {
                    while (k < h && nums[h] == nums[h - 1]) h--;
                    h--;
                }
            }
        }
    }
    *returnSize = ptr_ra + 1;
    return returnArray;
}

/*
 * @Author: AGOGIN 
 * @Date: 2019-08-23 11:26:49 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-08-23 20:41:41
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = malloc(sizeof(int) * 2);
    if (nums[0] > target || nums[numsSize - 1] < target) {
        *returnSize = 0;
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    int flag = 0;
    if (nums[0] == target) {
        ret[0] = 0;
        flag++;
    }
    if (nums[numsSize - 1] == target) {
        ret[1] = numsSize - 1;
        flag++;
    }
    if (flag == 2) {
        return ret;
    }

    int i = 1, j = numsSize - 2;
    int temp = numsSize;
    while (nums[i - 1] >= target || nums[i] != target) {
        if (temp != 1) {
            temp = temp >> 1;
        }
        if (nums[i + temp] <= target) {
            i += temp;
        }
    }
    temp = numsSize;
    while (nums[j + 1] <= target || nums[j] != target) {
        if (temp != 1) {
            temp = temp >> 1;
        }
        if (nums[j - temp] > target) {
            j -= temp;
        }
    }
    returnSize = j - i;
    ret[0] = i;
    ret[1] = j;
    return ret;
}

main() {
    int nums[] = {5,7,7,8,8,10};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 8;
    int returnSize;
    int* ret = searchRange(nums, numsSize, target, &returnSize);
    printf("%d\n %d\n", ret[0], ret[1]);
}

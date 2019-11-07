/*
 * @Author: AGOGIN
 * @Date: 2019-11-07 18:10:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-07 18:14:10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    for (int i = 0; i < numsSize; i++) {
        nums[(nums[i] - 1) % numsSize] += numsSize;
    }
    int* res = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= numsSize) {
            res[(*returnSize)++] = i + 1;
        }
    }
    return res;
}

int main() {

    return 0;
}
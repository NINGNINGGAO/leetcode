/*
 * @Author: AGOGIN
 * @Date: 2019-11-16 21:58:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-16 22:14:09
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define abs(a) ((a) > 0 ? (a) : (-(a)))
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int* res = malloc(sizeof(int) * 2);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        nums[abs(nums[i]) - 1] *= -1;
        if (nums[abs(nums[i]) - 1] > 0) {
            res[(*returnSize)++] = abs(nums[i]);
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0 && res[0] != i + 1) {
            res[(*returnSize)++] = i + 1;
        }
    }
    return res;
}

int main() {

    return 0;
}
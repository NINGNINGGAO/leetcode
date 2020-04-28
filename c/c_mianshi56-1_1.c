/*
 * @Author: AGOGIN 
 * @Date: 2020-04-28 16:29:52 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-28 16:43:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);
    memset(ret, 0, sizeof(int) * 2);
    int temp = 0;
    //整体取异或，得到两个只出现一次的数字的异或值
    for (int i = 0; i < numsSize; i++) temp ^= nums[i];
    int bit = 1;
    while ((temp & bit) == 0) bit <<= 1;
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & bit) != 0) ret[0] ^= nums[i];
        else ret[1] ^= nums[i];
    }
    return ret;
}

int main() {
    int nums[] = {1,2,10,4,1,4,3,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* ret = singleNumbers(nums, numsSize, &returnSize);
    printf("%d\t%d\n", ret[0], ret[1]);
    return 0;
}
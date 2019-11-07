/*
 * @Author: AGOGIN
 * @Date: 2019-11-07 17:56:37
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-07 18:05:35
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* nums, int index1, int index2) {
    if (index1 == index2) return;
    nums[index1] = nums[index1] ^ nums[index2];
    nums[index2] = nums[index1] ^ nums[index2];
    nums[index1] = nums[index1] ^ nums[index2];
}
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums, i, nums[i] - 1);
        }
    }
    int* res = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            res[(*returnSize)++] = i + 1;
        }
    }
    return res;
}

int main() {

    return 0;
}
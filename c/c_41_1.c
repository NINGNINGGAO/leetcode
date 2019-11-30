/*
 * @Author: AGOGIN
 * @Date: 2019-11-30 17:05:13
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-30 17:36:14
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int firstMissingPositive(int* nums, int numsSize){
    int flag = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            flag++;
            break;
        }
    }
    if (flag == 0) return 1;
    if (numsSize == 1) return 2;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0 || nums[i] > numsSize) nums[i] = 1;
    }
    for (int i = 0; i < numsSize; i++) {
        int a = abs(nums[i]);
        if (a == numsSize) nums[0] = -abs(nums[0]);
        else nums[a] = -abs(nums[a]);
    }
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > 0) return i;
    }
    if (nums[0] > 0) return numsSize;
    return numsSize + 1;
}

int main() {
    int nums[] = {2,1};
    int numsSize = sizeof(nums) / sizeof(int);
    int res = firstMissingPositive(nums, numsSize);
    printf("%d\n", res);
    return 0;
}
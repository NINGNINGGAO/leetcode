/*
 * @Author: AGOGIN
 * @Date: 2019-08-23 11:26:49
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-27 17:29:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* res = malloc(sizeof(int) * 2);
    for (int i = 0; i < 2; i++) {
        res[i] = -1;
    }
    if (numsSize <= 0) return res;
    int left = 0, right = numsSize;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    if (left == numsSize) return res;
    else res[0] = (nums[left] == target ? left : -1);
    left = 0, right = numsSize;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    if (left == 0) return res;
    else res[1] = (nums[left - 1] == target ? (left - 1) : -1);
    return res;
}

main() {
    int nums[] = {1};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 0;
    int returnSize;
    int* ret = searchRange(nums, numsSize, target, &returnSize);
    printf("%d\n %d\n", ret[0], ret[1]);
}

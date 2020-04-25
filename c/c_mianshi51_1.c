/*
 * @Author: AGOGIN 
 * @Date: 2020-04-24 22:56:04 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-24 23:26:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

void merge(int* nums, int* tmp, int l, int r, int rightEnd, int* ret) {
    int leftEnd = r - 1;
    int idx = l;
    int tmpNums = rightEnd - l + 1;
    while (l <= leftEnd && r <= rightEnd) {
        if (nums[l] <= nums[r]) tmp[idx++] = nums[l++];
        else {
            tmp[idx++] = nums[r++];
            *ret += leftEnd - l + 1;
        }
    }
    while (l <= leftEnd) tmp[idx++] = nums[l++];
    while (r <= rightEnd) tmp[idx++] = nums[r++];
    for (int i = 0; i < tmpNums; i++, rightEnd--) {
        nums[rightEnd] = tmp[rightEnd];
    }
}

void mSort(int* nums, int* tmp, int l, int rightEnd, int* ret) {
    int center;
    if (l < rightEnd) {
        center = (l + rightEnd) / 2;
        mSort(nums, tmp, l, center, ret);
        mSort(nums, tmp, center + 1, rightEnd, ret);
        merge(nums, tmp, l, center + 1, rightEnd, ret);
    }
}

int reversePairs(int* nums, int numsSize){
    if (numsSize < 2) return 0;
    int* tmp = malloc(sizeof(int) * numsSize);
    int ret = 0;
    mSort(nums, tmp, 0, numsSize - 1, &ret);
    free(tmp);
    return ret;
}

int main() {
    int nums[] = {7,5,6,4};
    int numsSize = sizeof(nums) / sizeof(int);
    int ret = reversePairs(nums, numsSize);
    printf("%d\n", ret);
    return 0;
}
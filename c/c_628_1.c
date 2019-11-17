/*
 * @Author: AGOGIN
 * @Date: 2019-11-16 11:44:03
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-16 12:15:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void insert(int* nums, int numsSize, int target) {
    int i;
    for (i = numsSize - 2; i >= 0; i--) {
        if (nums[i] > target) break;
        nums[i + 1] = nums[i];
    }
    nums[i + 1] = target;
}

int maximumProduct(int* nums, int numsSize){
    int maxNums = 3, minNums = 2;
    int* maxThreeNums = malloc(sizeof(int) * maxNums);
    int* minTwoNums = malloc(sizeof(int) * minNums);
    for (int i = 0; i < maxNums; i++) {
        maxThreeNums[i] = INT_MIN;
    }
    for (int i = 0; i < minNums; i++) {
        minTwoNums[i] = INT_MIN;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >maxThreeNums[maxNums - 1]) {
            insert(maxThreeNums, maxNums, nums[i]);
        }
        if ((-nums[i]) > minTwoNums[minNums - 1]) {
            insert(minTwoNums, minNums, -nums[i]);
        }
    }
    int L = minTwoNums[0] * minTwoNums[1];
    int R = maxThreeNums[1] * maxThreeNums[2];
    int res = L > R ? L : R;
    return res * maxThreeNums[0];
}

int main() {
    int nums[] = {1,2,3,4};
    int numsSize = sizeof(nums) / sizeof(int);
    int res = maximumProduct(nums, numsSize);
    return 0;
}
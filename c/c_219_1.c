/*
 * @Author: AGOGIN
 * @Date: 2019-10-28 10:28:48
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-28 11:15:10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if (numsSize <= 1 || k < 1) return false;
    int numsMax = nums[0], numsMin = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > numsMax) numsMax = nums[i];
        if (nums[i] < numsMin) numsMin = nums[i];
    }
    int* hash = malloc(sizeof(int) * (numsMax - numsMin + 1));
    for (unsigned int i = 0; i < numsMax - numsMin + 1; i++) {
        hash[i] = 0;
    }
    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        if (hash[nums[i] - numsMin] != 0) return true;
        else hash[nums[i] - numsMin]++;
        len++;
        if (len > k) {
            hash[nums[i - k] - numsMin] = 0;
            len--;
        }
    }
    return false;
}

int main() {
    int nums[] = {1,0,1,1};
    int numsSize = sizeof(nums) / sizeof(int);
    bool res = containsNearbyDuplicate(nums, numsSize, 1);
    return 0;
}
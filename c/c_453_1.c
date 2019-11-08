/*
 * @Author: AGOGIN
 * @Date: 2019-11-08 10:00:10
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-08 10:06:35
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int Min(int* nums, int numsSize) {
    int res = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < res) res = nums[i];
    }
    return res;
}
int Sum(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res += nums[i];
    }
    return res;
}
int minMoves(int* nums, int numsSize){
    int numsMin = Min(nums, numsSize);
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res += nums[i] - numsMin;
    }
    return res;
}

int main() {

    return 0;
}
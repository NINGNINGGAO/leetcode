/*
 * @Author: AGOGIN
 * @Date: 2019-11-19 11:33:32
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 11:48:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int sum(int* nums, int begin, int end) {
    int res = 0;
    for (int i = begin; i <= end; i++) {
        res += nums[i];
    }
    return res;
}
int pivotIndex(int* nums, int numsSize){
    int numsSum = sum(nums, 0, numsSize - 1);
    int leftSum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0) leftSum += nums[i - 1];
        if (numsSum - nums[i] == 2 * leftSum) return i;
    }
    return -1;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-19 20:26:21
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 20:34:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int dominantIndex(int* nums, int numsSize){
    int max = 0;
    int i;
    for (i = 1; i < numsSize; i++) {
        if (nums[i] > nums[max]) max = i;
    }
    for (i = 0; i < numsSize; i++) {
        if (i != max && (nums[i] << 1)> nums[max]) return -1;
    }
    return max;
}

int main() {

    return 0;
}
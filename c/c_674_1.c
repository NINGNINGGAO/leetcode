/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 18:33:08
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 18:35:53
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int findLengthOfLCIS(int* nums, int numsSize){
    if (numsSize <= 0) return 0;
    int res = 1;
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) count++;
        else {
            res = res > count ? res : count;
            count = 1;
        }
    }
    res = res > count ? res : count;
    return res;
}

int main() {

    return 0;
}
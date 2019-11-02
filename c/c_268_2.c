/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 11:00:02
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 11:01:36
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int missingNumber(int* nums, int numsSize){
    int res = 0;
    for (int i = 1; i < numsSize + 1; i++) {
        res ^= i;
    }
    for (int i = 0; i < numsSize; i++) {
        res ^= nums[i];
    }
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-10-23 09:42:14
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-23 09:45:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int singleNumber(int* nums, int numsSize){
    if (numsSize == 0) return NULL;
    int ret = nums[0];
    for (int i = 1; i < numsSize; i++) {
        ret ^= nums[i];
    }
    return ret;
}

int main() {

    return 0;
}
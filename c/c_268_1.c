/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 10:51:52
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 10:59:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int missingNumber(int* nums, int numsSize){
    int res = (numsSize + 1) * numsSize / 2;
    for (int i = 0; i < numsSize; i++) {
        res -= nums[i];
    }
    return res;
}

int main() {

    return 0;
}
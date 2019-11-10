/*
 * @Author: AGOGIN
 * @Date: 2019-11-10 17:16:46
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-10 17:20:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
int findMaxConsecutiveOnes(int* nums, int numsSize){
    int res = 0;
    int countNum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) countNum++;
        else {
            res = Max(res, countNum);
            countNum = 0;
        }
    }
    res = Max(res, countNum);
    return res;
}

int main() {

    return 0;
}
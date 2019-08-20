/*
 * @Author: AGOGIN 
 * @Date: 2019-08-20 15:22:35 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-08-20 15:29:08
 */
#include <stdio.h>
#include <stdlib.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize){
    int sumOdd = 0, sumEven = 0;
    int i;
    for (i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            sumOdd += nums[i];
            sumOdd = Max(sumOdd, sumEven);
        } else {
            sumEven += nums[i];
            sumEven = Max(sumOdd, sumEven);
        }
    }
    return Max(sumOdd, sumEven);
}


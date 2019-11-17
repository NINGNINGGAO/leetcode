/*
 * @Author: AGOGIN
 * @Date: 2019-11-16 21:53:03
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-16 21:57:06
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
double findMaxAverage(int* nums, int numsSize, int k){
    double max = 0;
    for (int i = 0; i < k; i++) {
        max += nums[i];
    }
    double temp = max;
    for (int i = k; i < numsSize; i++) {
        temp -= nums[i - k];
        temp += nums[i];
        max = Max(temp, max);
    }
    return max / k;
}

int main() {

    return 0;
}
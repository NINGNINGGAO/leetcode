/*
 * @Author: AGOGIN 
 * @Date: 2020-03-25 00:02:15 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-25 00:23:28
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int massage(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    if (numsSize == 1) return *nums;
    int** dp = malloc(sizeof(int*) * 2);
    dp[0] = malloc(sizeof(int) * numsSize);
    dp[1] = malloc(sizeof(int) * numsSize);
    memset(dp[0], 0, sizeof(int) * numsSize);
    memset(dp[1], 0, sizeof(int) * numsSize);
    dp[0][0] = 0;
    dp[1][0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[0][i] = Max(dp[0][i - 1], dp[1][i - 1])
        dp[1][i] = dp[0][i - 1] + nums[i];
    }
    int ret = Max(dp[0][numsSize - 1], dp[1][numsSize - 1]);
    free(dp[0]);
    free(dp[1]);
    free(dp);
    return ret;
}

int main() {
    
    return 0;
}
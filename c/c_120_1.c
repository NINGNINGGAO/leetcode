/*
 * @Author: AGOGIN 
 * @Date: 2020-03-20 15:21:32 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-20 21:16:20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if (triangleSize == 0) return 0;
    int* dp = malloc(sizeof(int) * triangleSize);
    dp[0] = triangle[0][0];
    for (int i = 1; i < triangleSize; i++) {
        dp[i] = dp[i - 1] + triangle[i][i];
        for (int j = triangleColSize[i] - 2; j > 0; j--) {
            dp[j] = Min(dp[j], dp[j - 1]) + triangle[i][j];
        }
        dp[0] = dp[0] + triangle[i][0];
    }
    int ret = dp[0];
    for (int i = 1; i < triangleSize; i++) ret = Min(ret, dp[i]);
    free(dp);
    return ret;
}

int main() {
    int n = 2;
    int** dp = malloc(sizeof(int*) * n);
    dp[0] = malloc(sizeof(int) * 2);
    dp[1] = malloc(sizeof(int) * 2);
    dp[0][0] = -1;
    dp[1][0] = -2;
    dp[1][1] = -3;
    int m[] = {1,2};
    int ret = minimumTotal(dp, n, m);
    return 0;
}
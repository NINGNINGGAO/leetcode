/*
 * @Author: AGOGIN 
 * @Date: 2020-04-11 14:01:54 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-11 15:18:33
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int superEggDrop(int K, int N){
    if (K == 0 || N == 0) return 0;
    int** dp = malloc(sizeof(int*) * (N + 1));
    for (int i = 0; i <= N; i++) {
        dp[i] = malloc(sizeof(int) * (K + 1));
        memset(dp[i], 0, sizeof(int) * (K + 1));
    }
    for (int i = 1; i <= N; i++) dp[i][1] = i;
    for (int i = 1; i <= K; i++) dp[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            int left = 1;
            int right = i;
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                int breakCount = dp[mid - 1][j - 1];
                int notBreakCount =dp[i - mid][j];
                if (breakCount > notBreakCount) right = mid - 1;
                else left = mid;
            }
            dp[i][j] = 1 + Max(dp[left - 1][j - 1], dp[i - left][j]);
        }
    }
    int ret = dp[N][K];
    for (int i = 0; i <= N; i++) free(dp[i]);
    free(dp);
    return ret;
}

int main() {
    
    return 0;
}
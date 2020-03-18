/*
 * @Author: AGOGIN 
 * @Date: 2020-03-18 19:35:46 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-18 20:06:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int numDistinct(char * s, char * t){
    int ret = 0;
    int sLen = strlen(s), tLen = strlen(t);
    if (sLen < tLen) return ret;
    long** dp = (long**)malloc(sizeof(long*) * (tLen + 1));
    for (int i = 0; i <= tLen; i++) {
        dp[i] = (int*)malloc(sizeof(long) * (sLen + 1));
        memset(dp[i], 0, sizeof(long) * (sLen + 1));
    }
    for (int i = 0; i <= sLen; i++) dp[0][i] = 1;
    for (int i = 1; i <= tLen; i++) {
        for (int j = 1; j <= sLen; j++) {
            if (t[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            else dp[i][j] = dp[i][j - 1];
        }
    }
    ret = dp[tLen][sLen];
    for (int i = 0; i < tLen; i++) free(dp[i]);
    return ret;
}

int main() {
    
    return 0;
}
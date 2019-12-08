/*
 * @Author: AGOGIN
 * @Date: 2019-12-08 13:58:54
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-08 14:41:37
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isInterleave(char * s1, char * s2, char * s3){
    int aLen = strlen(s1), bLen = strlen(s2), cLen = strlen(s3);
    if (aLen + bLen != cLen) return false;
    bool** dp = malloc(sizeof(bool*) * (aLen + 1));
    for (int i = 0; i <= aLen; i++) {
        dp[i] = malloc(sizeof(bool) * (bLen + 1));
        memset(dp[i], 0, sizeof(bool) * (bLen + 1));
    }
    dp[0][0] = true;
    for (int i = 1; i <= aLen; i++) {
        if (s1[i - 1] == s3[i - 1]) dp[i][0] = true;
        else break;
    }
    for (int i = 1; i <= bLen; i++) {
        if (s2[i - 1] == s3[i - 1]) dp[0][i] = true;
        else break;
    }
    for (int i = 1; i <= aLen; i++) {
        for (int j = 1; j <= bLen; j++) {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    bool res = dp[aLen][bLen];
    for (int i = 0; i <= aLen; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

int main() {
    char s1[] = "aabcc";
    char s2[] = "dbbca";
    char s3[] = "aadbbcbcac";
    bool res = isInterleave(s1,s2,s3);
    return 0;
}
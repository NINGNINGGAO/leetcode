/*
 * @Author: AGOGIN
 * @Date: 2019-11-30 19:45:43
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 10:50:57
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isMatch(char * s, char * p){
    int sLen = strlen(s) + 1, pLen = strlen(p) + 1;
    int** dp = malloc(sizeof(int*) * sLen);
    for (int i = 0; i < sLen; i++) {
        dp[i] = malloc(sizeof(int) * pLen);
        memset(dp[i], 0, sizeof(int) * pLen);
    }
    for (int i = 1; i < pLen; i++) {
        if (p[i - 1] == '*') dp[0][i] = 1;
        else break;
    }
    dp[0][0] = 1;
    for (int i = 1; i < sLen; i++) {
        for (int j = 1; j < pLen; j++) {
            if ((s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1]) dp[i][j] = 1;
            else if (p[j - 1] == '*' && (dp[i - 1][j] || dp[i][j - 1])) dp[i][j] = 1;
        }
    }
    bool res = dp[sLen - 1][pLen - 1];
    for (int i = 0; i < sLen; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

int main() {
    char s[] = "aa";
    char p[] = "*";
    bool res = isMatch(s, p);
    return 0;
}
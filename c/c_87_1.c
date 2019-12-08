/*
 * @Author: AGOGIN
 * @Date: 2019-12-08 19:26:44
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-08 20:37:29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isSame(char* s1, char* s2) {
    int flag1[128] = {0}, flag2[128] = {0};
    for (int i = 0; i < strlen(s1); i++) {
        flag1[s1[i]]++;
        flag2[s2[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (flag1[i] != flag2[i]) return false;
    }
    return true;
}
bool isScramble(char * s1, char * s2){
    int aLen = strlen(s1), bLen = strlen(s2);
    if (aLen != bLen) return false;
    if (aLen == 0) return true;
    if (isSame(s1, s2) == false) return false;
    if (aLen <= 2) return true;
    int len = aLen + 1;
    bool*** dp = malloc(sizeof(bool**) * len);
    for (int i = 0; i < len; i++) {
        dp[i] = malloc(sizeof(bool*) * aLen);
        for (int j = 0; j < aLen; j++) {
            dp[i][j] = malloc(sizeof(bool) * aLen);
            memset(dp[i][j], 0, sizeof(bool) * aLen);
        }
    }
    for (int i = 0; i < aLen; i++) {
        for (int j = 0; j < aLen; j++) {
            if (s1[i] == s2[j]) dp[1][i][j] = true;
        }
    }
    for (int num = 2; num < len; num++) {
        for (int i = 0; i + num < len; i++) {
            for (int j = 0; j + num < len; j++) {
                for (int k = 1; k < num; k++) {
                    if ((dp[k][i][j] && dp[num - k][i + k][j + k]) || (dp[k][i][j + num - k] && dp[num - k][i + k][j])) {
                        dp[num][i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    bool res = dp[aLen][0][0];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < aLen; j++) {
            for (int k = 0; k < aLen; k++) {
                printf("%d\t", dp[i][j][k]);
            }
            printf("\n");
            free(dp[i][j]);
        }
        printf("\n\n");
        free(dp[i]);
    }
    free(dp);
    return res;
}

int main() {
    char s1[] = "great";
    char s2[] = "rgeat";
    bool res = isScramble(s1, s2);
    printf("%d\n",res);
    return 0;
}
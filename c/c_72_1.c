/*
 * @Author: AGOGIN
 * @Date: 2019-12-04 10:14:25
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-04 10:40:33
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define threeNumsMin(a, b, c) (((a) < (b) ? (a) : (b)) < (c) ? ((a) < (b) ? (a) : (b)) : (c))
int minDistance(char * word1, char * word2){
    int aLen = strlen(word1), bLen = strlen(word2);
    int** dp = malloc(sizeof(int*) * (aLen + 1));
    for (int i = 0; i < (aLen + 1); i++) {
        dp[i] = malloc(sizeof(int) * (bLen + 1));
        memset(dp[i], 0, sizeof(int) * (bLen + 1));
    }
    for (int i = 1; i < (aLen + 1); i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i < (bLen + 1); i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i < (aLen + 1); i++) {
        for (int j = 1; j < (bLen + 1); j++) {
            if (word1[i - 1] != word2[j - 1]) dp[i][j] = threeNumsMin(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            else dp[i][j] = dp[i - 1][j - 1];
        }
    }
    int res = dp[aLen][bLen];
    for (int i = 0; i < (aLen + 1); i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

int main() {
    char a[] = "zoologicoarchaeologist";
    char b[] = "zoogeologist";
    int res = minDistance(a, b);
    return 0;
}
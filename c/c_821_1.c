/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 19:29:25
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 20:25:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char * S, char C, int* returnSize){
    int sLen = strlen(S);
    *returnSize = sLen;
    if (sLen == 0) return NULL;
    int* L = malloc(sizeof(int) * sLen);
    int* R = malloc(sizeof(int) * sLen);
    int flag = -1;
    for (int i = 0; i < sLen; i++) {
        if (S[i] != C) {
            if (flag != -1) L[i] = i - flag;
            else L[i] = INT_MAX;
        }
        else {
            flag = i;
            L[i] = 0;
        }
    }
    flag = -1;
    for (int i = sLen - 1; i >= 0; i--) {
        if (S[i] != C) {
            if (flag != -1) R[i] = flag - i;
            else R[i] = INT_MAX;
        }
        else {
            flag = i;
            R[i] = 0;
        }
    }
    int* res = malloc(sizeof(int) * sLen);
    for (int i = 0; i < sLen; i++) {
        res[i] = L[i] < R[i] ? L[i] : R[i];
    }
    free(L);
    free(R);
    return res;
}

int main() {
    char S[] = "loveleetcode";
    char C = 'e';
    int num;
    int* res = shortestToChar(S, C, &num);
    for (int i = 0; i < num; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
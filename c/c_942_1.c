/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 12:38:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 12:43:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize){
    int sLen = strlen(S);
    int p = 0, q = sLen;
    *returnSize = sLen + 1;
    int* res = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < sLen; i++) {
        if (S[i] == 'I') {
            res[i] = p++;
        } else if (S[i] == 'D') {
            res[i] = q--;
        }
    }
    res[(*returnSize) - 1] = p;
    return res;
}

int main() {

    return 0;
}
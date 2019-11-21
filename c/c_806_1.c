/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 09:40:51
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 09:51:08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
    *returnSize = 0;
    int sLen = strlen(S);
    if (sLen == 0) return NULL;
    *returnSize = 2;
    int* res = malloc(sizeof(int) * 2);
    memset(res, 0, sizeof(int) * 2);
    res[0]++;
    for (int i = 0; i < sLen; i++) {
        res[1] += widths[S[i] - 'a'];
        if (res[1] > 100) {
            res[0]++;
            res[1] = widths[S[i] - 'a'];
        }
    }
    return res;
}

int main() {

    return 0;
}
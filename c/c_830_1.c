/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 21:15:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 21:25:20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char * S, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int sLen = strlen(S);
    if (sLen == 0) return NULL;
    int** res = malloc(sizeof(int*) * 512);
    *returnColumnSizes = malloc(sizeof(int) * 512);
    memset(res, 0, sizeof(int*) * 512);
    int count = 1;
    char temp = S[0];
    for (int i = 1; i < sLen; i++) {
        if (S[i] == temp) count++;
        else {
            if (count > 2) {
                res[*returnSize] = malloc(sizeof(int) * 2);
                (*returnColumnSizes)[*returnSize] = 2;
                res[*returnSize][0] = i - count;
                res[*returnSize][1] = i - 1;
                (*returnSize)++;
            }
            temp = S[i];
            count = 1;
        }
    }
    if (count > 2) {
        res[*returnSize] = malloc(sizeof(int) * 2);
        (*returnColumnSizes)[*returnSize] = 2;
        res[*returnSize][0] = sLen - count;
        res[*returnSize][1] = sLen - 1;
        (*returnSize)++;
    }
    return res;
}

int main() {

    return 0;
}
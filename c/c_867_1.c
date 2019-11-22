/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 13:01:54
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 13:06:13
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
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = AColSize[0];
    *returnColumnSizes = malloc(sizeof(int) * AColSize[0]);
    int** res = malloc(sizeof(int*) * AColSize[0]);
    for (int i = 0; i < AColSize[0]; i++) {
        res[i] = malloc(sizeof(int) * ASize);
        (*returnColumnSizes)[i] = ASize;
        for (int j = 0; j < ASize; j++) {
            res[i][j] = A[j][i];
        }
    }
    return res;
}

int main() {

    return 0;
}
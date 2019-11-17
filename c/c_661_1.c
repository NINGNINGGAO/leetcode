/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 16:54:00
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 17:26:29
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
int** imageSmoother(int** M, int MSize, int* MColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (MSize <= 0 || *MColSize <= 0) return NULL;
    *returnColumnSizes = malloc(sizeof(int) * MSize);
    int** res = malloc(sizeof(int*) * MSize);
    int temp, count;
    *returnSize = MSize;
    for (int i = 0; i < MSize; i++) {
        res[i] = malloc(sizeof(int) * (MColSize[i]));
        for (int j = 0; j < MColSize[i]; j++) {
            count = 1;
            temp = M[i][j];
            if (i > 0) {
                temp += M[i - 1][j];
                count++;
            }
            if (j > 0) {
                temp += M[i][j - 1];
                count++;
            }
            if (i > 0 && j > 0) {
                temp += M[i - 1][j - 1];
                count++;
            }
            if (i < MSize - 1) {
                temp += M[i + 1][j];
                count++;
            }
            if (j < MColSize[i] - 1) {
                temp += M[i][j + 1];
                count++;
            }
            if (i < MSize - 1 && j < MColSize[i] - 1) {
                temp += M[i + 1][j + 1];
                count++;
            }
            if (i < MSize - 1 && j > 0) {
                temp += M[i + 1][j - 1];
                count++;
            }
            if (i > 0 && j < MColSize[i] - 1) {
                temp += M[i - 1][j + 1];
                count++;
            }
            res[i][j] = temp / count;
        }
        (*returnColumnSizes)[i] = MColSize[i];
    }
    return res;
}

int main() {
    int MSize = 5;
    int MColSize[] = {3,3,3,3,3};
    int** M = malloc(sizeof(int*) * MSize);
    for (int i = 0; i < MSize; i++) {
        M[i] = malloc(sizeof(int) * MColSize[i]);
        M[i][0] = 3 * i + 2;
        M[i][1] = 3 * i + 3;
        M[i][2] = 3 * i + 4;
    }
    int returnSize, *returnColSize;
    int** res = imageSmoother(M, MSize, MColSize, &returnSize, &returnColSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSize[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
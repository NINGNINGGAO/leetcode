/*
 * @Author: AGOGIN
 * @Date: 2019-11-14 17:45:32
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-14 22:06:09
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
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    if (r * c != numsSize * (*numsColSize)) {
        *returnSize = numsSize;
        *returnColumnSizes = malloc(sizeof(int) * r);
        int** res = malloc(sizeof(int*) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            (*returnColumnSizes)[i] = *numsColSize;
            res[i] = malloc(sizeof(int) * (*numsColSize));
            for (int j = 0; j < *numsColSize; j++) {
                res[i][j] = nums[i][j];
            }
        }
        return res;
    }
    int** res = malloc(sizeof(int*) * r);
    *returnSize = r;
    *returnColumnSizes = malloc(sizeof(int) * r);
    memset(*returnColumnSizes, 0, sizeof(int) * r);
    int row = 0, col = 0;
    int flag = 0;
    int i, j;
    for (i = 0; i < r; i++) {
        res[i] = malloc(sizeof(int) * c);
        for (j = 0; j < c; j++) {
            res[i][j] = nums[row][col++];
            if (col == (*numsColSize)) {
                row++;
                col = 0;
            }
        }
        (*returnColumnSizes)[i] = c;
    }
    return res;
}

int main() {
    int numsSize = 2;
    int numsColSize = 2;
    int** nums = malloc(sizeof(int*) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = malloc(sizeof(int) * numsColSize);
        for (int j = 0; j < numsColSize; j++) {
            nums[i][j] = (i + 1) * (j + 2);
        }
    }
    int returnSize;
    int* returnColSize;
    int** res = matrixReshape(nums, numsSize, &numsColSize, 1, 4, &returnSize, &returnColSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSize[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
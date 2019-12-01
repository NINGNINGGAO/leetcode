/*
 * @Author: AGOGIN
 * @Date: 2019-12-01 18:34:19
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 18:51:57
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize = 0;
    if (matrixSize == 0) return NULL;
    int n = matrixSize * matrixColSize[0];
    int* res = malloc(sizeof(int) * n);
    int* flag = malloc(sizeof(int) * 4);
    memset(flag, 0, sizeof(int) * 4);
    flag[1] = matrixColSize[0] - 1;
    flag[3] = matrixSize - 1;
    while (true) {
        for (int i = flag[0]; i <= flag[1]; i++) {
            res[(*returnSize)++] = matrix[flag[2]][i];
        }
        flag[2]++;
        if (flag[2] > flag[3]) break;
        for (int i = flag[2]; i <= flag[3]; i++) {
            res[(*returnSize)++] = matrix[i][flag[1]];
        }
        flag[1]--;
        if (flag[1] < flag[0]) break;
        for (int i = flag[1]; i >= flag[0]; i--) {
            res[(*returnSize)++] = matrix[flag[3]][i];
        }
        flag[3]--;
        if (flag[3] < flag[2]) break;
        for (int i = flag[3]; i >= flag[2]; i--) {
            res[(*returnSize)++] = matrix[i][flag[0]];
        }
        flag[0]++;
        if (flag[0] > flag[1]) break;
    }
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 16:13:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 16:38:31
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
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    int num = gridSize * gridColSize[0];
    k %= num;
    int** res = malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        res[i] = malloc(sizeof(int) * gridColSize[i]);
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            int temp = (i * gridColSize[0] + j + k) % num;
            res[temp / gridColSize[0]][temp % gridColSize[0]] = grid[i][j];
        }
    }
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-10-21 16:00:06
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-21 16:21:17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    if (numRows == 0) {
        *returnSize = 0;
        returnColumnSizes = NULL;
        return NULL;
    }
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    int** ret = malloc(sizeof(int*) * numRows);
    ret[0] = malloc(sizeof(int));
    ret[0][0] = 1;
    *returnSize = numRows;
    (*returnColumnSizes)[0] = 1;
    for (int i = 1; i < numRows; i++) {
        ret[i] = malloc(sizeof(int) * (i + 1));
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; j++) {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        (*returnColumnSizes)[i] = i + 1;
    }
    return ret;
}

int main() {

    return 0;
}
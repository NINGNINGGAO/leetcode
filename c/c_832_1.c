/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 21:28:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 21:47:50
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
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = ASize;
    *returnColumnSizes = AColSize;
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < (AColSize[i] + 1)/ 2; j++) {
            int temp = A[i][j] ^ 1;
            A[i][j] = A[i][AColSize[i] - 1 - j] ^ 1;
            A[i][AColSize[i] - 1 - j] = temp;
        }
    }
    return A;
}

int main() {

    return 0;
}
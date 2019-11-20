/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 10:34:21
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 10:35:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < matrixColSize[i]; j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) return false;
        }
    }
    return true;
}

int main() {

    return 0;
}
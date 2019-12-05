/*
 * @Author: AGOGIN
 * @Date: 2019-12-04 10:43:40
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-04 11:00:32
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int row = 0, col = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                if (j == 0) col = 1;
                if (i == 0) row = 1;
            }
        }
    }
    for (int i = 1; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < matrixColSize[i]; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrixColSize[0]; i++) {
        if (matrix[0][i] == 0) {
            for (int j = 1; j < matrixSize; j++) {
                matrix[j][i] = 0;
            }
        }
    }
    if (row == 1) {
        for (int i = 0; i < matrixColSize[0]; i++) {
            matrix[0][i] = 0;
        }
    }
    if (col == 1) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {

    return 0;
}
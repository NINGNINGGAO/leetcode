/*
 * @Author: AGOGIN
 * @Date: 2019-12-01 15:53:59
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 16:29:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < (matrixSize + 1) / 2; i++) {
        for (int j = 0; j < matrixSize / 2; j++) {
            int temp = matrix[matrixSize - 1 - j][i];
            matrix[matrixSize - 1 - j][i] = matrix[matrixSize - 1 - i][matrixSize - 1 - j];
            matrix[matrixSize - 1 - i][matrixSize - 1 - j] = matrix[j][matrixSize - 1 - i];
            matrix[j][matrixSize - 1 - i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

int main() {

    return 0;
}
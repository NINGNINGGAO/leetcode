/*
 * @Author: AGOGIN 
 * @Date: 2020-04-07 15:20:46 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-07 15:32:06
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void swap(int *a, int *b) {
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            swap(&(matrix[i][j]), &(matrix[matrixSize - 1 - i][j]));
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < i; j++) {
            swap(&(matrix[i][j]), &(matrix[j][i]));
        }
    }
}

int main() {
    int **a = malloc(sizeof(int*) * 3);
    int b[] = {1, 2, 3};
    int c[] = {4, 5, 6};
    int d[] = {7, 8, 9};
    a[0] = b;
    a[1] = c;
    a[2] = d;
    int f[] = {3, 3, 3};
    rotate(a, 3, f);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
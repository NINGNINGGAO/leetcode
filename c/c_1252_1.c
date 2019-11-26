/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 16:00:05
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 16:05:26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int* rows = malloc(sizeof(int) * n);
    int* cols = malloc(sizeof(int) * m);
    memset(rows, 0, sizeof(int) * n);
    memset(cols, 0, sizeof(int) * m);
    for (int i = 0; i < indicesSize; i++) {
        rows[indices[i][0]]++;
        cols[indices[i][1]]++;
    }
    int oddRows = 0, oddCols = 0;
    for (int i = 0; i < n; i++) {
        if (rows[i] % 2 == 1) oddRows++;
    }
    for (int i = 0; i < m; i++) {
        if (cols[i] % 2 == 1) oddCols++;
    }
    free(rows);
    free(cols);
    return oddRows * (m - oddCols) + oddCols * (n - oddRows);
}

int main() {

    return 0;
}
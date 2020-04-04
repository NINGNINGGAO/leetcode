/*
 * @Author: AGOGIN 
 * @Date: 2020-03-29 11:33:03 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2020-03-29 11:33:03 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define INF 1222

int maxDistance(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 0) return 0;
    int** dpF = malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        dpF[i] = malloc(sizeof(int) * gridColSize[i]);
        for (int j = 0; j < gridColSize[i]; j++) {
            dpF[i][j] = grid[i][j] ? 0 : INF;
        }
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) continue;
            if (i > 0) dpF[i][j] = Min(dpF[i][j], dpF[i - 1][j] + 1);
            if (j > 0) dpF[i][j] = Min(dpF[i][j], dpF[i][j - 1] + 1);
        }
    }
    for (int i = gridSize - 1; i >= 0; i--) {
        for (int j = gridColSize[i] - 1; j >= 0; j--) {
            if (grid[i][j] == 1) continue;
            if (i < gridSize - 1) dpF[i][j] = Min(dpF[i][j], dpF[i + 1][j] + 1);
            if (j < gridColSize[i] - 1) dpF[i][j] = Min(dpF[i][j], dpF[i][j + 1] + 1);
        }
    }
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (!grid[i][j]) ret = Max(dpF[i][j], ret);
        }
        free(dpF[i]);
    }
    free(dpF);
    if (ret == INF) return -1;
    return ret;
}

int main() {
    int **grid = malloc(sizeof(int*) * 3);
    int a[] = {1, 0, 0};
    int b[] = {0, 0, 0};
    int c[] = {0, 0, 0};
    grid[0] = a;
    grid[1] = b;
    grid[2] = c;
    int col[] = {3, 3, 3};
    int ret = maxDistance(grid, 3, col);
    printf("%d\n", ret);
    return 0;
}
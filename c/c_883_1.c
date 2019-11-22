/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 15:11:43
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 15:25:39
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int projectionArea(int** grid, int gridSize, int* gridColSize){
    int* maxGrid = malloc(sizeof(int) * gridSize);
    int* maxGridCol = malloc(sizeof(int) * gridColSize[0]);
    memset(maxGrid, 0, sizeof(int) * gridSize);
    memset(maxGridCol, 0, sizeof(int) * gridColSize[0]);
    int count1 = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            maxGrid[i] = maxGrid[i] > grid[i][j] ? maxGrid[i] : grid[i][j];
            maxGridCol[j] = maxGridCol[j] > grid[i][j] ? maxGridCol[j] : grid[i][j];
            if (grid[i][j] > 0) count1++;
        }
    }
    int count2 = 0, count3 = 0;
    for (int i = 0; i < gridSize; i++) {
        count2 += maxGrid[i];
    }
    for (int i = 0; i < gridColSize[0]; i++) {
        count3 += maxGridCol[i];
    }
    return count1 + count2 + count3;
}

int main() {

    return 0;
}
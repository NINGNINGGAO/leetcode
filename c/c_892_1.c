/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 16:22:57
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 16:35:21
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] > 0) {
                res += (grid[i][j] * 4 + 2);
                if (i > 0) res -= grid[i - 1][j] < grid[i][j] ? grid[i - 1][j] : grid[i][j];
                if (i < gridColSize[i] - 1) res -= grid[i + 1][j] < grid[i][j] ? grid[i + 1][j] : grid[i][j];
                if (j > 0) res -= grid[i][j - 1] < grid[i][j] ? grid[i][j - 1] : grid[i][j];
                if (j < gridSize - 1) res -= grid[i][j + 1] < grid[i][j] ? grid[i][j + 1] : grid[i][j];
            }
        }
    }
    return res;
}

int main() {

    return 0;
}
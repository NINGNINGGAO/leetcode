/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 21:48:02
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 22:30:57
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isGrid(int** grid, int rs, int rc) {
    if (grid[rs + 1][rc + 1] != 5) return false;
    int* hash = malloc(sizeof(int) * 10);
    memset(hash, 0, sizeof(int) * 10);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hash[grid[rs + i][rc + j] % 10]++;
        }
    }
    for (int i = 1; i < 10; i++) {
        if (hash[i] != 1) return false;
    }
    int L1 = 0, L2 = 0, R1 = 0, R2 = 0;
    for (int i = 0; i < 3; i++) {
        L1 += grid[rs][rc + i];
        L2 += grid[rs + 2][rc + i];
        R1 += grid[rs + i][rc];
        R2 += grid[rs + i][rc + 2];
    }
    if (L1 != 15 || L2 != 15 || R1 != 15 || R2 != 15) return false;
    return true;
}
int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    for (int i = 0; i < gridSize - 2; i++) {
        for (int j = 0; j < gridColSize[i] - 2; j++) {
            res += isGrid(grid, i, j);
        }
    }
    return res;
}

int main() {
    int** grid = malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) {
        grid[i] = malloc(sizeof(int) * 4);
    }
    int a = 3;
    grid[0][0] = 4;
    grid[0][1] = 3;
    grid[0][2] = 8;
    grid[1][0] = 9;
    grid[1][1] = 5;
    grid[1][2] = 1;
    grid[2][0] = 2;
    grid[2][1] = 7;
    grid[2][2] = 6;
    int b[] = {4,4,4};
    int res = numMagicSquaresInside(grid, a, b);
    return 0;
}
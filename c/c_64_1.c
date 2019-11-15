/*
 * @Author: AGOGIN
 * @Date: 2019-09-06 17:39:58
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:43:04
 */
#include <stdio.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int arr[*gridColSize];
    arr[0] = grid[0][0];
    for (int i = 1; i < *gridColSize; i++) {
        arr[i] = arr[i - 1] + grid[0][i];
    }
    for (int i = 1; i < gridSize; i++) {
        arr[0] += grid[i][0];
        for (int j = 1; j < *gridColSize; j++) {
            arr[j] = Min(arr[j - 1], arr[j]) + grid[i][j];
        }
    }
    return arr[*gridColSize - 1];
}

int main() {

}
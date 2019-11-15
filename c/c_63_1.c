/*
 * @Author: AGOGIN
 * @Date: 2019-09-06 14:57:01
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:43:03
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}
int main() {
    int obstacleGridSize = 24, obstacleGridColSize = 65;
    //scanf("%d %d", &obstacleGridSize, &obstacleGridColSize);
    int arr[24][65] = {{0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},{1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0},{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},{0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1},{1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1},{1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0}};
    int* obstacleGrid[obstacleGridSize];
    for (int i = 0; i < obstacleGridSize; i++) {
        obstacleGrid[i] = arr[i];
    }
    /*int** obstacleGrid = NULL;
    obstacleGrid = malloc(sizeof(int*) * obstacleGridSize);
    for (int i = 0; i < obstacleGridSize; i++) {
        obstacleGrid[i] = malloc(sizeof(int) * obstacleGridColSize);
        for (int j = 0; j < obstacleGridColSize; j++) {
            scanf("%d", &obstacleGrid[i][j]);
        }
    }*/
    int ret = uniquePathsWithObstacles(obstacleGrid, obstacleGridSize, &obstacleGridColSize);
    printf("%d\n", ret);
    return 0;
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    unsigned int a[*obstacleGridColSize];
    int flag = 0;
    for (int i = 0; i < *obstacleGridColSize; i++) {
        if (obstacleGrid[0][i] == 1) {
            flag = 1;
        }
        if (flag == 0) {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }
    flag = 0;
    for (int i = 1; i < obstacleGridSize; i++) {
        if (obstacleGrid[i][0] != 0) {
            flag = 1;
        }
        if (flag == 1) {
            a[0] = 0;
        }
        for (int j = 1; j < *obstacleGridColSize; j++) {
            if (obstacleGrid[i][j] == 0) {
                a[j] = a[j] + a[j - 1];
            } else {
                a[j] = 0;
            }
        }
    }
    return a[*obstacleGridColSize - 1];
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 22:06:05
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 22:25:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node {
    int bad;
    int good;
    int time;
};
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    struct Node* org = malloc(sizeof(struct Node));
    memset(org, 0, sizeof(struct Node));
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 2) (org->bad)++;
            else if (grid[i][j] == 1) (org->good)++;
        }
    }
    if (org->good == 0) return 0;
    if (org->bad == 0) return -1;
    int temp = org->good;
    while (temp) {
        (org->time)++;
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridColSize[i]; j++) {
                if (grid[i][j] == 2) {
                    if (i > 0 && grid[i - 1][j] == 1) {
                        grid[i - 1][j] = 3;
                        (org->bad)++;
                        (org->good)--;
                    }
                    if (i < gridSize - 1 && grid[i + 1][j] == 1) {
                        grid[i + 1][j] = 3;
                        (org->bad)++;
                        (org->good)--;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        grid[i][j - 1] = 3;
                        (org->bad)++;
                        (org->good)--;
                    }
                    if (j < gridColSize[i] - 1 && grid[i][j + 1] == 1) {
                        grid[i][j + 1] = 3;
                        (org->bad)++;
                        (org->good)--;
                    }
                }
            }
        }
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridColSize[i]; j++) {
                if (grid[i][j] == 3) grid[i][j] = 2;
            }
        }
        if (org->good == temp) return -1;
        temp = org->good;
    }
    return org->time;
}

int main() {

    return 0;
}
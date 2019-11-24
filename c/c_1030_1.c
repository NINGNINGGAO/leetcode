/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 16:41:05
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 22:00:57
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct Node {
    int x[2];
    int dist;
};
int distanceManhattan(int* a, int* b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
int cmp(const void* a, const void* b) {
    return ((struct Node*)a)->dist - ((struct Node*)b)->dist;
}
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    int num = R * C;
    int** res = malloc(sizeof(int*) * num);
    struct Node* arr = malloc(sizeof(struct Node) * num);
    int count = 0;
    int flag[2] = {r0, c0};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            arr[count].x[0] = i;
            arr[count].x[1] = j;
            arr[count].dist = distanceManhattan(arr[count].x, flag);
            count++;
        }
    }
    qsort(arr, num, sizeof(struct Node), cmp);
    *returnSize = num;
    *returnColumnSizes = malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++) {
        (*returnColumnSizes)[i] = 2;
        res[i] = malloc(sizeof(int) * 2);
        res[i][0] = arr[i].x[0];
        res[i][1] = arr[i].x[1];
    }
    free(arr);
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-12-02 17:26:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-02 17:45:34
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
int cmp(const void* a, const void* b) {
    int temp = (*(int**)a)[0] - (*(int**)b)[0];
    if (temp != 0) return temp;
    else return (*(int**)a)[1] - (*(int**)b)[1];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (intervalsSize == 0) return NULL;
    *returnColumnSizes = malloc(sizeof(int) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    int** res = malloc(sizeof(int*) * intervalsSize);
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    res[*returnSize] = intervals[0];
    int mid;
    for (int i = 1; i < intervalsSize; i++) {
        if (res[*returnSize][1] >= intervals[i][0]) {
            res[*returnSize][1] = res[*returnSize][1] > intervals[i][1] ? res[*returnSize][1] : intervals[i][1];
        } else {
            (*returnSize)++;
            res[*returnSize] = intervals[i];
        }
    }
    (*returnSize)++;
    return res;
}
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int** temp = malloc(sizeof(int*) * (intervalsSize + 1));
    for (int i = 0; i < intervalsSize; i++) {
        temp[i] = intervals[i];
    }
    temp[intervalsSize] = newInterval;
    int** res = merge(temp, intervalsSize + 1, intervalsColSize, returnSize, returnColumnSizes);
    return res;
}


int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 15:08:34
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 15:21:06
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
#define maxSize 20480
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = 0;
    int** res = malloc(sizeof(int*) * maxSize);
    *returnColumnSizes = malloc(sizeof(int) *maxSize);
    int minDiff = INT_MAX;
    int temp;
    for (int i = 0; i < arrSize - 1; i++) {
        temp = arr[i + 1] - arr[i];
        minDiff = minDiff < temp ? minDiff : temp;
    }
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i + 1] - arr[i] == minDiff) {
            res[*returnSize] = malloc(sizeof(int) * 2);
            res[*returnSize][0] = arr[i];
            res[*returnSize][1] = arr[i + 1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }
    return res;
}

int main() {

    return 0;
}
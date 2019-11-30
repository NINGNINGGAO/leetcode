/*
 * @Author: AGOGIN
 * @Date: 2019-11-28 09:45:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-28 10:11:55
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
int* arrCopy(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    int* res = malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++) {
        res[i] = arr[i];
    }
    return res;
}
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** res, int* arr, int arrSize) {
    for (int i = 0; i < candidatesSize; i++) {
        if (candidates[i] < target) {
            if (arrSize > 0 && arr[arrSize - 1] > candidates[i]) continue;
            arr[arrSize] = candidates[i];
            dfs(candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, res, arr, arrSize + 1);
        } else if (candidates[i] == target) {
            if (arrSize > 0 && arr[arrSize - 1] > candidates[i]) break;
            arr[arrSize++] = candidates[i];
            res[*returnSize] = arrCopy(arr, arrSize, &(*returnColumnSizes)[*returnSize]);
            (*returnSize)++;
        } else {
            break;
        }
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    *returnSize = 0;
    int** res = malloc(sizeof(int*) * 1024);
    *returnColumnSizes = malloc(sizeof(int) * 1024);
    int* arr = malloc(sizeof(int) * 512);
    int arrSize = 0;
    dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, res, arr, arrSize);
    return res;
}

int main() {
    int nums[] = {2,3,5};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 8;
    int n;
    int* m;
    int** res = combinationSum(nums, numsSize, target, &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
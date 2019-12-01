/*
 * @Author: AGOGIN
 * @Date: 2019-12-01 17:30:18
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 18:09:00
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
int factorial(int n) {
    if (n > 0) return n * factorial(n - 1);
    else return 1;
}
void numsCopy(int** res, int* returnSize, int* temp, int numsSize) {
    res[*returnSize] = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        res[*returnSize][i] = temp[i];
    }
    (*returnSize)++;
}
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*) b;
}
void backTrack(int* nums, int numsSize, int* returnSize, int** res, int* temp, bool* flag, int count) {
    if (count == numsSize) {
        numsCopy(res, returnSize, temp, numsSize);
    } else {
        for (int i = 0; i < numsSize; i++) {
            if (flag[i] == false) {
                if (i > 0 && nums[i] == nums[i - 1] && flag[i - 1] == false) continue;
                temp[count] = nums[i];
                flag[i] = true;
                backTrack(nums, numsSize, returnSize,res, temp, flag, count + 1);
                flag[i] = false;
            }
        }
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int n = factorial(numsSize);
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    bool* flag = malloc(sizeof(bool) * numsSize);
    memset(flag, 0, sizeof(bool) * numsSize);
    int** res = malloc(sizeof(int*) * n);
    int* temp = malloc(sizeof(int) * numsSize);
    int count = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    backTrack(nums, numsSize, returnSize, res, temp, flag, 0);
    free(temp);
    free(flag);
    return res;
}

int main() {
    int nums[] = {1,2,1};
    int numsSize = sizeof(nums) / sizeof(int);
    int n;
    int* m;
    int** res = permuteUnique(nums, numsSize, &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
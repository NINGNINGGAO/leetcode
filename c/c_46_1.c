/*
 * @Author: AGOGIN
 * @Date: 2019-12-01 16:30:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 18:10:15
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
void backTrack(int* nums, int numsSize, int* returnSize, int** res, int* temp, bool* flag, int count) {
    if (count == numsSize) {
        numsCopy(res, returnSize, temp, numsSize);
    } else {
        for (int i = 0; i < numsSize; i++) {
            if (flag[i] == false) {
                temp[count] = nums[i];
                flag[i] = true;
                backTrack(nums, numsSize, returnSize,res, temp, flag, count + 1);
                flag[i] = false;
            }
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
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
    backTrack(nums, numsSize, returnSize, res, temp, flag, 0);
    free(temp);
    free(flag);
    return res;
}

int main() {
    int nums[] = {1,2,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int n;
    int* m;
    int** res = permute(nums, numsSize, &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
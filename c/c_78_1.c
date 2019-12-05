/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 15:26:08
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-12-05 15:26:08
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
void numsCopy(int** res, int* returnSize, int** returnColumnSizes, int* nums, int count) {
    res[*returnSize] = malloc(sizeof(int) * count);
    (*returnColumnSizes)[*returnSize] = count;
    for (int i = 0; i < count; i++) {
        res[*returnSize][i] = nums[i];
    }
    (*returnSize)++;
}
void backTrack(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** res, int* flag, int first, int mid, int count) {
    if (mid == count) {
        numsCopy(res, returnSize, returnColumnSizes, flag, count);
    } else {
        for (int i = first; i < numsSize; i++) {
            flag[mid] = nums[i];
            backTrack(nums, numsSize, returnSize, returnColumnSizes, res, flag, i + 1, mid + 1, count);
        }
    }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize == 0) return NULL;
    const int maxNum = 10240;
    int** res = malloc(sizeof(int*) * maxNum);
    *returnColumnSizes = malloc(sizeof(int) * maxNum);
    int* flag = malloc(sizeof(int) * numsSize);
    for (int count = 0; count <= numsSize; count++) {
        backTrack(nums, numsSize, returnSize, returnColumnSizes, res, flag, 0, 0, count);
    }
    return res;
}

int main() {

    return 0;
}
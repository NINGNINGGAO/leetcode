/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 15:25:51
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-12-05 15:25:51
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
int countNum(int n, int k) {
    if (k > n) return 0;
    else if (k == n || k == 0) return 1;
    else return countNum(n-1,k) + countNum(n-1, k-1);
}
void numsCopy(int** res, int* returnSize, int* nums, int k) {
    res[*returnSize] = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        res[*returnSize][i] = nums[i];
    }
    (*returnSize)++;
}
void backTrack(int n, int k, int* returnSize, int** res, int* nums, int count, int first) {
    if (count == k) {
        numsCopy(res, returnSize, nums, k);
    } else {
        for (int i = first; i <= n; i++) {
            nums[count] = i;
            backTrack(n, k, returnSize, res, nums, count + 1, i + 1);
        }
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (n < k) return NULL;
    int num = countNum(n, k);
    *returnColumnSizes = malloc(sizeof(int) * num);
    int** res = malloc(sizeof(int*) * num);
    for (int i = 0; i < num; i++) {
        (*returnColumnSizes)[i] = k;
    }
    int* nums = malloc(sizeof(int) * k);
    int count = 0;
    int first = 1;
    backTrack(n, k, returnSize, res, nums, count, first);
    return res;
}

int main() {

    return 0;
}
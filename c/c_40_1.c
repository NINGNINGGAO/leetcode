/*
 * @Author: AGOGIN
 * @Date: 2019-11-30 15:13:07
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-30 17:00:57
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
    int* nums;
    int numsSize;
};
int isSame(int* nums1, int* nums2, int numsSize) {
    int temp;
    for (int i = 0; i < numsSize; i++) {
        temp = (nums1[i]) - (nums2[i]);
        if (temp < 0) return -1;
        else if (temp > 0) return 1;
    }
    return 0;
}
#define maxSize 1024
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int nodeCmp(const void* a, const void* b) {
    int aLen = ((struct Node*)a)->numsSize, bLen = ((struct Node*)b)->numsSize;
    if (aLen < bLen) return -1;
    else if (aLen > bLen) return 1;
    else return isSame((((struct Node*)a)->nums), (((struct Node*)b)->nums), aLen);
}
void numsCopy(int** res, int* returnSize, int** returnColumnSizes, int* flag, int flagSize) {
    res[*returnSize] = malloc(sizeof(int) * flagSize);
    for (int i = 0; i < flagSize; i++) {
        res[*returnSize][i] = flag[i];
    }
    (*returnColumnSizes)[*returnSize] = flagSize;
    (*returnSize)++;
}
void backTrack(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, \
int** res, int* flag, int flagSize, int num) {
    if (target == 0) {
        numsCopy(res, returnSize, returnColumnSizes, flag, flagSize);
        return;
    } else {
        for (int i = num; i < candidatesSize; i++) {
            if (i > 0 && flagSize == 0 && candidates[i] == candidates[i - 1]) continue;
            flag[flagSize] = candidates[i];
            if (target - candidates[i] >= 0) backTrack(candidates, candidatesSize, target - candidates[i], returnSize, \
            returnColumnSizes, res, flag, flagSize + 1, i + 1);
            else break;
        }
    }
}
void deleteRepeat(int** res, int* returnSize, int** returnColumnSizes) {
    if (*returnSize <= 0) return;
    int count = *returnSize;
    struct Node* arr = malloc(sizeof(struct Node) * count);
    *returnSize = 0;
    for (int i = 0; i < count; i++) {
        arr[i].nums = res[i];
        arr[i].numsSize = (*returnColumnSizes)[i];
    }
    qsort(arr, count, sizeof(struct Node), nodeCmp);
    numsCopy(res, returnSize, returnColumnSizes, arr[0].nums, arr[0].numsSize);
    for (int i = 1; i < count; i++) {
        if (nodeCmp(&(arr[i]), &(arr[i - 1])) != 0) {
            numsCopy(res, returnSize, returnColumnSizes, arr[i].nums, arr[i].numsSize);
        }
    }
    for (int i = 0; i < count; i++) {
        free(arr[i].nums);
    }
    free(arr);
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * maxSize);
    memset(*returnColumnSizes, 0, sizeof(int) * maxSize);
    int** res = malloc(sizeof(int*) * maxSize);
    int* flag = malloc(sizeof(int) * candidatesSize);
    int flagSize = 0;
    backTrack(candidates, candidatesSize, target, returnSize, returnColumnSizes, res, flag, flagSize, 0);
    deleteRepeat(res, returnSize, returnColumnSizes);
    return res;
}

int main() {
    int nums[] = {2,5,2,1,2};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 5;
    int n;
    int* m;
    int** res = combinationSum2(nums, numsSize, target, &n, &m);
    return 0;
}
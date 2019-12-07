/*
 * @Author: AGOGIN
 * @Date: 2019-12-07 14:31:25
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-07 17:14:49
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
    int val;
    int fre;
};
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
void numsCopy(int** res, int* returnSize, int** returnColumnSizes, int* storage, int storageSize) {
    res[*returnSize] = malloc(sizeof(int) * storageSize);
    (*returnColumnSizes)[*returnSize] = storageSize;
    for (int i = 0; i < storageSize; i++) {
        res[*returnSize][i] = storage[i];
    }
    (*returnSize)++;
}
bool backTrack(int* nums, int numsSize, int** res, int* returnSize, int** returnColumnSizes, \
int* storage, int storageSize, int count, int first, struct Node* flag, int flagSize) {
    if (storageSize == count) {
        numsCopy(res, returnSize, returnColumnSizes, storage, storageSize);
    } else {
        for (int i = first; i < flagSize; i++) {
            for (int j = 1; j <= flag[i].fre; j++) {
                if (storageSize + j > count) break;
                for (int k = 0; k < j; k++) {
                    storage[storageSize + k] = flag[i].val;
                }
                backTrack(nums, numsSize, res, returnSize, returnColumnSizes, \
                storage, storageSize + j, count, i + 1, flag, flagSize);
            }
        }
    }
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize <= 0) return NULL;
    qsort(nums, numsSize, sizeof(int), cmp);
    struct Node* flag = malloc(sizeof(struct Node) * numsSize);
    memset(flag, 0, sizeof(struct Node) * numsSize);
    flag[0].val = nums[0];
    flag[0].fre = 1;
    int flagSize = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) (flag[flagSize].fre)++;
        else {
            flagSize++;
            flag[flagSize].val = nums[i];
            flag[flagSize].fre = 1;
        }
    }
    flagSize++;
    int maxSize = 10240;
    int** res = malloc(sizeof(int*) * maxSize);
    *returnColumnSizes = malloc(sizeof(int) * maxSize);
    memset(*returnColumnSizes, 0, sizeof(int) * maxSize);
    *returnSize = 1;
    int* storage = malloc(sizeof(int) * numsSize);
    for (int i = 1; i <= numsSize; i++) {
        backTrack(nums, numsSize, res, returnSize, returnColumnSizes, storage, 0, i, 0, flag, flagSize);
    }
    free(storage);
    free(flag);
    return res;
}

int main() {
    int nums[] = {1,2,2};
    int numsSize = sizeof(nums) / sizeof(int);
    int n;
    int* m;
    int** res = subsetsWithDup(nums, numsSize, &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m[i]; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
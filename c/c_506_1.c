/*
 * @Author: AGOGIN
 * @Date: 2019-11-12 09:55:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-12 10:53:26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Data {
    int index;
    int val;
};
int cmp(const void *a, const void *b) {
    return -(((struct Data*)a)->val - ((struct Data*)b)->val);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRelativeRanks(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if (numsSize == 0) return NULL;
    struct Data* d = malloc(sizeof(struct Data) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        d[i].index = i;
        d[i].val = nums[i];
    }
    qsort(d, numsSize, sizeof(struct Data), cmp);
    char** res = malloc(sizeof(char*) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        switch (i) {
            case 0:
                res[d[i].index] = malloc(sizeof(char*) * 11);
                res[d[i].index][0] = '\0';
                sprintf(res[d[i].index], "Gold Medal");
                break;
            case 1:
                res[d[i].index] = malloc(sizeof(char*) * 13);
                res[d[i].index][0] = '\0';
                sprintf(res[d[i].index], "Silver Medal");
                break;
            case 2:
                res[d[i].index] = malloc(sizeof(char*) * 13);
                res[d[i].index][0] = '\0';
                sprintf(res[d[i].index], "Bronze Medal");
                break;
            default:
                res[d[i].index] = malloc(sizeof(char*) * 2);
                res[d[i].index][0] = '\0';
                sprintf(res[d[i].index], "%d", i + 1);
                break;
        }
    }
    return res;
}

int main() {

    return 0;
}
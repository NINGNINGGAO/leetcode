/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 18:10:01
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 20:17:53
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
void deleterepeat(int* nums, int numsSize, int* returnSize) {
    *returnSize = 1;
    int temp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != temp) {
            nums[(*returnSize)++] = nums[i];
            temp = nums[i];
        }
    }
}
int* powerfulIntegers(int x, int y, int bound, int* returnSize){
    *returnSize = 0;
    int* res = malloc(sizeof(int) * 512);
    int count = 0;
    memset(res, 0, sizeof(int) * 512);
    for (int i = 0; i < 20 && pow(x, i) <= bound; i++) {
        for (int j = 0; j < 20 && pow(y, j) <= bound; j++) {
            int temp = (int)pow(x, i) + (int)pow(y, j);
            if (temp <= bound) res[count++] = temp;
        }
    }
    if (count > 0) {
        qsort(res, count, sizeof(int), cmp);
        deleterepeat(res, count, returnSize);
    }
    return res;
}

int main() {
    int n;
    int* res = powerfulIntegers(1,1,0,&n);
    return 0;
}
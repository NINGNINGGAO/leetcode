/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 21:06:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 21:33:14
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int* numMovesStones(int a, int b, int c, int* returnSize){
    int arr[3] = {a, b, c};
    qsort(arr, 3, sizeof(int), cmp);
    int* res = malloc(sizeof(int) * 2);
    memset(res, 0, sizeof(int) * 2);
    res[1] = arr[2] - arr[0] - 2;
    res[0] += (arr[2] - arr[1]) == 1 ? 0 : 1;
    res[0] += (arr[1] - arr[0]) == 1 ? 0 : 1;
    res[0] = (arr[1] - arr[0] == 2 || arr[2] - arr[1] == 2) ? 1 : res[0];
    *returnSize = 2;
    return res;
}

int main() {
    int n;
    int* res = numMovesStones(1,2,5, &n);
    return 0;
}
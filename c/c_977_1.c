/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 20:22:08
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 20:23:48
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
int* sortedSquares(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    for (int i = 0; i < ASize; i++) {
        A[i] = A[i] * A[i];
    }
    qsort(A, ASize, sizeof(int), cmp);
    return A;
}

int main() {

    return 0;
}
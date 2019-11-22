/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 21:49:28
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 21:52:58
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
    return ((*(int*)a) % 2) - ((*(int*)b) % 2);
}
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    qsort(A, ASize, sizeof(int), cmp);
    return A;
}

int main() {

    return 0;
}
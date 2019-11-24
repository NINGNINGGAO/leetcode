/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 12:00:20
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 12:07:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    bool* res = malloc(sizeof(bool) * ASize);
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        sum = (sum << 1) + A[i];
        sum %= 5;
        if (sum == 0) res[i] = true;
        else res[i] = false;
    }
    return res;
}

int main() {
    int A[] = {0,1,1};
    int ASize = sizeof(A) / sizeof(int);
    int n;
    bool* res = prefixesDivBy5(A, ASize, &n);
    return 0;
}
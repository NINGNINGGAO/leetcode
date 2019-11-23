/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 21:08:43
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 21:20:09
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int maxSize = ASize > 5 ? ASize : 5;
    int* res = malloc(sizeof(int) * (maxSize + 1));
    memset(res, 0, sizeof(int) * (maxSize + 1));
    int count = 0;
    int num = K;
    int i = ASize - 1;
    while (i >= 0 || num > 0) {
        if (i >= 0) num += A[i];
        res[count++] = num % 10;
        num /= 10;
        i--;
    }
    int temp;
    for (int i = 0; i < count / 2; i++) {
        temp = res[i];
        res[i] = res[count - 1 - i];
        res[count - 1 - i] = temp;
    }
    *returnSize = count;
    return res;
}

int main() {
    int a[] = {0};
    int n;
    int* res = addToArrayForm(a, 0, 10000, &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 15:45:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 16:12:22
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
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    qsort(A, ASize, sizeof(int), cmp);
    qsort(B, BSize, sizeof(int), cmp);
    int aSum = 0, bSum = 0;
    for (int i = 0; i < ASize; i++) {
        aSum += A[i];
    }
    for (int i = 0; i < BSize; i++) {
        bSum += B[i];
    }
    int diff = (aSum - bSum) / 2;
    int fast = 0, slow = 0;
    int* res = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int temp;
    while (fast < ASize && slow < BSize) {
        temp = A[fast] - B[slow];
        if (temp == diff) {
            res[0] = A[fast];
            res[1] = B[slow];
            return res;
        } else if (temp < diff) fast++;
        else if (temp > diff) slow++;
    }
    return res;
}

int main() {
    int A[] = {35,17,4,24,10};
    int an = 5;
    int B[] = {63,21};
    int bn = 2;
    int n;
    int* res = fairCandySwap(A, an, B, bn, &n);
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 10:46:30
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 10:58:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    int odd = 1, even = 0;
    int temp;
    int flag = 0;
    while (odd < ASize && even < ASize) {
        while (odd < ASize && A[odd] % 2 == 1) odd += 2;
        while (even < ASize && A[even] % 2 == 0) even += 2;
        if (odd < ASize && even < ASize) {
            temp = A[odd];
            A[odd] = A[even];
            A[even] = temp;
            odd += 2;
            even += 2;
        }
    }
    return A;
}

int main() {
    int A[] = {4,1,1,0,1,0};
    int num = sizeof(A) / sizeof(int);
    int n;
    int* res = sortArrayByParityII(A, num, &n);
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 20:24:34
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 21:01:01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    *returnSize = queriesSize;
    int* res = malloc(sizeof(int) * queriesSize);
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) sum += A[i];
    }
    for (int i = 0; i < queriesSize; i++) {
        if (A[queries[i][1]] % 2 == 0) sum -= A[queries[i][1]];
        A[queries[i][1]] += queries[i][0];
        if (A[queries[i][1]] % 2 == 0) sum += A[queries[i][1]];
        res[i] = sum;
    }
    return res;
}

int main() {

    return 0;
}
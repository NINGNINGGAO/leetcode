/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 10:54:18
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 11:06:52
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    if (opsSize <= 0) return m * n;
    int* opsMin = malloc(sizeof(int) * (*opsColSize));
    for (int i = 0; i < (*opsColSize); i++) {
        opsMin[i] = INT_MAX;
    }
    for (int i = 0; i < opsSize; i++) {
        for (int j = 0; j < (*opsColSize); j++) {
            if (opsMin[j] > ops[i][j]) opsMin[j] = ops[i][j];
        }
    }
    int res = 1;
    for (int i = 0; i < (*opsColSize); i++) {
        res *= opsMin[i];
    }
    return res;
}

int main() {

    return 0;
}
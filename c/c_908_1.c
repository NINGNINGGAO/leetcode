/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 21:53:42
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 22:10:32
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int smallestRangeI(int* A, int ASize, int K){
    int min = A[0], max = A[0];
    for (int i = 1; i < ASize; i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }
    int diff = max - min;
    int temp = diff - 2 * K;
    int res = temp > 0 ? temp : 0;
    return res;
}

int main() {

    return 0;
}
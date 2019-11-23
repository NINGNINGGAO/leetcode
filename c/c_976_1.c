/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 20:18:02
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 20:23:49
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int largestPerimeter(int* A, int ASize){
    qsort(A, ASize, sizeof(int), cmp);
    for (int i = ASize - 3; i >= 0; i--) {
        if (A[i] + A[i + 1] > A[i + 2]) return A[i] + A[i + 1] + A[i + 2];
    }
    return 0;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 16:48:27
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 16:56:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isMonotonic(int* A, int ASize){
    int flag = A[0] < A[ASize - 1] ? 1 : -1;
    if (flag == -1) {
        for (int i = 1; i < ASize; i++) {
            if (A[i] > A[i - 1]) return false;
        }
    } else {
        for (int i = 1; i < ASize; i++) {
            if (A[i] < A[i - 1]) return false;
        }
    }
    return true;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 17:57:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 18:04:03
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int repeatedNTimes(int* A, int ASize){
    for (int j = 1; j <= 3; j++) {
        for (int i = 0; i < ASize - j; i++) {
            if (A[i] == A[i + j]) return A[i];
        }
    }
    return NULL;
}

int main() {

    return 0;
}
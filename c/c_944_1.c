/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 12:23:06
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 12:38:29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int minDeletionSize(char ** A, int ASize){
    if (ASize <= 1) return 0;
    int aLen = strlen(A[0]);
    int res = 0;
    char temp;
    for (int i = 0; i < aLen; i++) {
        for (int j = 1; j < ASize; j++) {
            temp = A[j - 1][i];
            if (A[j][i] < temp) {
                res++;
                break;
            }
        }
    }
    return res;
}

int main() {

    return 0;
}
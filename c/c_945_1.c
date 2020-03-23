/*
 * @Author: AGOGIN 
 * @Date: 2020-03-22 00:35:02 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-22 00:42:04
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define maxNum 80000

int minIncrementForUnique(int* A, int ASize){
    int* arr = malloc(sizeof(int) * maxNum);
    memset(arr, 0, sizeof(int) * maxNum);
    for (int i = 0; i < ASize; i++) arr[A[i]]++;

    int ret = 0, countNum = 0;
    for (int i = 0; i < maxNum; i++) {
        if (arr[i] >= 2) {
            countNum += arr[i] - 1;
            ret -= i * (arr[i] - 1);
        } else if (countNum > 0 && arr[i] == 0) {
            countNum--;
            ret += i;
        }
    }
    free(arr);
    return ret;
}

int main() {
    
    return 0;
}
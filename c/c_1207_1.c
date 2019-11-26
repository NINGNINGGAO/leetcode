/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 15:26:00
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 15:29:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool uniqueOccurrences(int* arr, int arrSize){
    int* arrHash = malloc(sizeof(int) * 2001);
    int* resHash = malloc(sizeof(int) * 1001);
    memset(arrHash, 0, sizeof(int) * 2001);
    memset(resHash, 0, sizeof(int) * 1001);
    for (int i = 0; i < arrSize; i++) {
        arrHash[arr[i] + 1000]++;
    }
    for (int i = 0; i < 2001; i++) {
        resHash[arrHash[i]]++;
        if (arrHash[i] != 0 && resHash[arrHash[i]] > 1) return false;
    }
    return true;
}

int main() {

    return 0;
}
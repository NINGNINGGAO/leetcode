/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 09:28:16
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 09:45:36
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int heightChecker(int* heights, int heightsSize){
    int* arr = malloc(sizeof(int) * 101);
    memset(arr, 0, sizeof(int) * 101);
    for (int i = 0; i < heightsSize; i++) {
        arr[heights[i]]++;
    }
    int res = 0;
    int mid = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < arr[i]; j++) {
            if (heights[mid] != i) res++;
            mid++;
        }
    }
    return res;
}

int main() {

    return 0;
}
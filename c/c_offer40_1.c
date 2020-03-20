/*
 * @Author: AGOGIN 
 * @Date: 2020-03-20 11:33:37 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-20 14:16:33
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSortSolution(int* arr, int begin, int end, int k) {
    if (begin >= end) return;
    int p = begin, q = end;
    int temp = arr[p];
    while (p < q) {
        while (p < q && arr[q] >= temp) q--;
        if (p < q) arr[p] = arr[q];
        while (p < q && arr[p] < temp) p++;
        if (p <q) arr[q] = arr[p];
    }
    arr[p] = temp;
    if (p < k) quickSortSolution(arr, p + 1, end, k);
    else if (p > k) quickSortSolution(arr, begin, p - 1, k);
    else if (p == k) return;
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    *returnSize = k;
    if (arrSize < k) {
        *returnSize = 0;
        return NULL;
    }
    if (arrSize == k) return arr;
    quickSortSolution(arr, 0, arrSize - 1, k);
    return arr;
}

int main() {
    int arr[] = {0,1,1,2,4,4,1,3,3,2};
    int arrSize = 10;
    int k = 6;
    int returnSize = 0;
    int* ret = getLeastNumbers(arr, arrSize, k, &returnSize);
    return 0;
}
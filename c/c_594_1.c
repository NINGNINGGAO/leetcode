/*
 * @Author: AGOGIN
 * @Date: 2019-11-14 22:49:06
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 10:54:25
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void deleteRepeat(int* nums, int numsSize, int** arr, int** countArr, int* arrSize) {
    *arr = malloc(sizeof(int) * numsSize);
    *countArr = malloc(sizeof(int) * numsSize);
    int temp = nums[0];
    int countNum = 1;
    *arrSize = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == temp) countNum++;
        else {
            (*arr)[*arrSize] = temp;
            (*countArr)[*arrSize] = countNum;
            countNum = 1;
            (*arrSize)++;
            temp = nums[i];
        }
    }
    (*arr)[*arrSize] = temp;
    (*countArr)[*arrSize] = countNum;
    (*arrSize)++;
}
int findLHS(int* nums, int numsSize){
    if (numsSize <= 0) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int *arr, *countArr;
    int arrSize;
    deleteRepeat(nums, numsSize, &arr, &countArr, &arrSize);
    int res = 0;
    int temp;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == 1) {
            temp = countArr[i - 1] + countArr[i];
            if (temp > res) res = temp;
        }
    }
    free(arr);
    free(countArr);
    return res;
}

int main() {
    int nums[] = {1,3,2,2,5,2,3,7};
    int numsSize = sizeof(nums) / sizeof(int);
    int res = findLHS(nums, numsSize);
    return 0;
}
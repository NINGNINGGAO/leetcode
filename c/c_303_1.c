/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 21:08:51
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 21:20:50
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
typedef struct {
    int numsSize;
    int *numsArray;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    NumArray* obj = malloc(sizeof(NumArray));
    obj->numsSize = numsSize;
    obj->numsArray = malloc(sizeof(int) * numsSize);
    obj->numsArray[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        obj->numsArray[i] = obj->numsArray[i - 1] + nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if (obj == NULL) return NULL;
    int res = res = obj->numsArray[j];
    if (i > 0) {
        res -= obj->numsArray[i - 1];
    }
    return res;
}

void numArrayFree(NumArray* obj) {
    if (obj != NULL) {
        free(obj->numsArray);
        free(obj);
    }
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);

 * numArrayFree(obj);
*/

int main() {

    return 0;
}
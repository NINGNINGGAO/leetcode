/*
 * @Author: AGOGIN
 * @Date: 2019-10-21 16:21:23
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-21 16:52:47
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int* ret = malloc(sizeof(int) * (rowIndex + 1));
    ret[0]= 1;
    for (int i = 1; i <= rowIndex; i++) {
        ret[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            ret[j] = ret[j] + ret[j - 1];
        }
    }
    return ret;
}

int main() {

    return 0;
}
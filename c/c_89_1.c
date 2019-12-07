/*
 * @Author: AGOGIN
 * @Date: 2019-12-06 21:07:51
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-07 14:02:59
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int num = 1<<n;
    int* res = malloc(sizeof(int) * num);
    memset(res, 0, sizeof(int) * num);
    *returnSize = 1;
    int head = 1;
    for (int i = 0; i < n; i++) {
        int mid = (*returnSize) - 1;
        for (int j = mid; j >= 0; j--) {
            res [(*returnSize)++] = res[j] + head;
        }
        head <<= 1;
    }
    return res;
}

int main() {

    return 0;
}
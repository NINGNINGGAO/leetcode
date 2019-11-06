/*
 * @Author: AGOGIN
 * @Date: 2019-11-05 15:16:34
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-05 15:23:37
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = 0;
    if (n <= 0) return NULL;
    char** res = malloc(sizeof(char*) * n);
    for (int i = 1; i <= n; i++) {
        res[*returnSize] = malloc(sizeof(char) * 9);
        res[*returnSize][0] = '\0';
        if (i % 3 == 0 && i % 5 == 0) {
            sprintf(res[*returnSize], "%sFizzBuzz", res[*returnSize]);
        } else if (i % 3 == 0) {
            sprintf(res[*returnSize], "%sFizz", res[*returnSize]);
        } else if (i % 5 == 0) {
            sprintf(res[*returnSize], "%sBuzz", res[*returnSize]);
        } else {
            sprintf(res[*returnSize], "%s%d", res[*returnSize], i);
        }
        (*returnSize)++;
    }
    return res;
}

int main() {

    return 0;
}
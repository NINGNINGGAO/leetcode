/*
 * @Author: AGOGIN
 * @Date: 2019-11-04 19:54:40
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-04 22:40:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define MAXSIZE 512
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countNum(int n) {
    int res = 0;
    while (n != 0) {
        n = n & (n - 1);
        res++;
    }
    return res;
}
char ** readBinaryWatch(int num, int* returnSize){
    *returnSize = 0;
    if (num < 0) return NULL;
    char** res = malloc(sizeof(char*) * MAXSIZE);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 60; j++) {
            if (countNum(i) + countNum(j) == num) {
                res[*returnSize] = malloc(sizeof(char) * 6);
                res[*returnSize][0] = '\0';
                sprintf(res[*returnSize], "%s%d:", res[*returnSize], i);
                if (j < 10) {
                    sprintf(res[*returnSize], "%s0%d", res[*returnSize], j);
                } else {
                    sprintf(res[*returnSize], "%s%d", res[*returnSize], j);
                }
                (*returnSize)++;
            }
        }
    }
    return res;
}

int main() {
    int num = 0;
    int returnSize;
    char** res = readBinaryWatch(num, &returnSize);
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 22:28:57
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 22:32:49
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fraction(int* cont, int contSize, int* returnSize){
    *returnSize = 2;
    int* res = malloc(sizeof(int) * 2);
    res[0] = cont[contSize - 1];
    res[1] = 1;
    int temp;
    for (int i = contSize - 2; i>= 0; i--) {
        temp = res[1];
        res[1] = res[0];
        res[0] = cont[i] * res[0] + temp;
    }
    return res;
}

int main() {

    return 0;
}
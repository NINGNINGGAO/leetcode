/*
 * @Author: AGOGIN
 * @Date: 2019-10-14 21:43:50
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-14 22:34:09
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* ret = malloc(sizeof(int) * (digitsSize + 1));
    for (int i = 0; i < digitsSize; i++) {
        ret[i + 1] = digits[i];
    }
    ret[0] = 1;
    for (int i = digitsSize; i > 0; i--) {
        if (ret[i] == 9) {
            ret[i] = 0;
        } else {
            ret[i]++;
            break;
        }
    }
    *returnSize = digitsSize;
    if (ret[1] == 0) {
        (*returnSize)++;
        return ret;
    } else {
        return ret + 1;
    }
}

int main() {
    int digits[] = {0};
    int digitsSize = sizeof(digits) / sizeof(int);
    int returnSize;
    int* ret = plusOne(digits, digitsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d\n", ret[i]);
    }
    return 0;
}

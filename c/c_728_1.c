/*
 * @Author: AGOGIN
 * @Date: 2019-11-19 11:39:24
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 11:48:01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    *returnSize = 0;
    int* res = malloc(sizeof(int) * (right - left + 1));
    int flag = 0, temp;;
    for (int i = left; i <= right; i++) {
        int n = i;
        while (n != 0) {
            flag = 0;
            temp = n % 10;
            n /= 10;
            if (temp == 0 || i % temp != 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) res[(*returnSize)++] = i;
    }
    return res;
}

int main() {

    return 0;
}
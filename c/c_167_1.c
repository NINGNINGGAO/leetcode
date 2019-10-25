/*
 * @Author: AGOGIN
 * @Date: 2019-10-25 10:06:04
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-25 10:23:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 0;
    if (numbersSize < 2) {
        return NULL;
    }
    int head = 0, last = numbersSize - 1;
    int* ret = NULL;
    int temp;
    while (head < last) {
        temp = numbers[head] + numbers[last];
        if (temp == target) {
            *returnSize = 2;
            ret = malloc(sizeof(int) * 2);
            ret[0] = head + 1;
            ret[1] = last + 1;
            return ret;
        } else if (temp > target) {
            last--;
        } else if (temp < target) {
            head++;
        }
    }
    return ret;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 18:59:21
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 19:09:04
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define maxSize 1024
struct List {
    int* nums;
    int numsSize;
};
int calPoints(char ** ops, int opsSize){
    struct List* obj = malloc(sizeof(struct List));
    obj->nums = malloc(sizeof(int) * maxSize);
    obj->numsSize = 0;
    for (int i = 0; i < opsSize; i++) {
        if (ops[i][0] == 'C') {
            (obj->numsSize)--;
        } else if (ops[i][0] == 'D') {
            obj->nums[obj->numsSize] = (obj->nums[(obj->numsSize) - 1]) * 2;
            (obj->numsSize)++;
        } else if (ops[i][0] == '+') {
            obj->nums[obj->numsSize] = obj->nums[(obj->numsSize) - 1] + obj->nums[(obj->numsSize) - 2];
            (obj->numsSize)++;
        } else {
            int temp = atoi(ops[i]);
            obj->nums[(obj->numsSize)++] = temp;
        }
    }
    int res = 0;
    for (int i = 0; i < obj->numsSize; i++) {
        res += obj->nums[i];
    }
    return res;
}

int main() {

    return 0;
}
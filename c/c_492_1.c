/*
 * @Author: AGOGIN
 * @Date: 2019-11-10 17:20:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-10 17:30:04
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){
    int num = sqrt(area) + 1;
    while (area % num != 0) num--;
    *returnSize = 2;
    int* res = malloc(sizeof(int) * 2);
    int mid = area / num;
    if (mid > num) {
        int temp = num;
        num = mid;
        mid = temp;
    }
    res[0] = num;
    res[1] = mid;
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-12-08 15:21:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-08 20:31:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int largestRectangleArea(int* heights, int heightsSize){
    if (heightsSize == 0) return 0;
    int* arrLeft = malloc(sizeof(int) * (heightsSize + 2));
    memset(arrLeft, 0, sizeof(int) * (heightsSize + 2));
    int* arrRight = malloc(sizeof(int) * (heightsSize + 2));
    memset(arrRight, 0, sizeof(int) * (heightsSize + 2));
    arrLeft[0] = -1;
    arrRight[heightsSize - 1] = heightsSize;
    for (int i = 1; i < heightsSize; i++) {
        int tmp = i - 1;
        while (tmp >= 0 && heights[tmp] >= heights[i]) tmp = arrLeft[tmp];
        arrLeft[i] = tmp;
    }
    for (int i = heightsSize - 2; i >= 0; i--) {
        int tmp = i + 1;
        while (tmp < heightsSize && heights[tmp] >= heights[i]) tmp = arrRight[tmp];
        arrRight[i] = tmp;
    }
    int res = 0;
    for (int i = 0; i < heightsSize; i++) {
        //printf("%d\t%d\n", arrLeft[i], arrRight[i]);
        int temp = ((arrRight[i] - arrLeft[i] - 1) * heights[i]);
        res = res > temp ? res : temp;
    }
    free(arrLeft);
    free(arrRight);
    return res;
}

int main() {
    int nums[] = {4,2,0,3,2,4,3,4};
    int numsSize = sizeof(nums) / sizeof(int);
    int res = largestRectangleArea(nums, numsSize);
    printf("%d\n", res);
    return 0;
}
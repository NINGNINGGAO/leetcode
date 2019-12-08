/*
 * @Author: AGOGIN
 * @Date: 2019-12-08 18:01:40
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-08 20:32:00
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
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0) return 0;
    int res = 0;
    int* nums = malloc(sizeof(int) * matrixColSize[0]);
    memset(nums, 0, sizeof(int) * matrixColSize[0]);
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == '1') nums[j]++;
            else nums[j] = 0;
        }
        int temp = largestRectangleArea(nums, matrixColSize[0]);
        res = res > temp ? res : temp;
    }
    free(nums);
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-30 17:54:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 11:41:56
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int trap(int* height, int heightSize){
    int res = 0;
    int* maxLeft = malloc(sizeof(int) * heightSize);
    int* maxRight = malloc(sizeof(int) * heightSize);
    memset(maxLeft, 0, sizeof(int) * heightSize);
    memset(maxRight, 0, sizeof(int) * heightSize);
    for (int i = 1; i < heightSize - 1; i++) {
        maxLeft[i] = maxLeft[i - 1] > height[i - 1] ? maxLeft[i - 1] : height[i - 1];
    }
    for (int i = heightSize - 2; i > 0; i--) {
        maxRight[i] = maxRight[i + 1] > height[i + 1] ? maxRight[i + 1] : height[i + 1];
    }
    for (int i = 1; i < heightSize - 1; i++) {
        int min = maxLeft[i] < maxRight[i] ? maxLeft[i] : maxRight[i];
        if (min > height[i]) res +=(min - height[i]);
    }
    free(maxLeft);
    free(maxRight);
    return res;
}

int main() {

    return 0;
}
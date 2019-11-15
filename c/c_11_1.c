/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:36:46
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:43:39
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    int i = 0;
    int j = heightSize - 1;
    int res = 0;

    while (i < j) {
        int temp1 = min(height[i],height[j]);
        int temp2 = temp1 * (j - i);
        res = max(res, temp2);
        height[i] < height[j] ? i++ : j--;
    }
    return res;
}

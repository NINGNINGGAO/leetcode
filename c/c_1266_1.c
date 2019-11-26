/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 16:38:37
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 16:43:29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int res = 0;
    int x, y;
    for (int i = 1; i < pointsSize; i++) {
        x = abs(points[i][0] - points[i - 1][0]);
        y = abs(points[i][1] - points[i - 1][1]);
        res += x > y ? x : y;
    }
    return res;
}

int main() {

    return 0;
}
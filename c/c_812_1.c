/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 11:39:07
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 14:47:48
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
double getArea(int* p1, int* p2, int* p3) {
    double dx1 = p2[0] - p1[0];
    double dx2 = p3[0] - p1[0];
    double dy1 = p2[1] - p1[1];
    double dy2 = p3[1] - p1[1];
    return abs(dx1 * dy2 - dx2 * dy1) / 2.0;
}
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    double res = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                double temp = getArea(points[i], points[j], points[k]);
                res = Max(res, temp);
            }
        }
    }
    return res;
}

int main() {

    return 0;
}
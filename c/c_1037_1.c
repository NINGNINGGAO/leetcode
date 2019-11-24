/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 20:58:11
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 21:05:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
double distanceTwoPoints(int* a, int* b, int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        temp += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt((double)temp);
}
bool isBoomerang(int** points, int pointsSize, int* pointsColSize){
    double a = distanceTwoPoints(points[0], points[1], 2);
    double b = distanceTwoPoints(points[0], points[2], 2);
    double c = distanceTwoPoints(points[1], points[2], 2);
    if (a + b > c && a + c > b && b + c > a) return true;
    return false;
}

int main() {

    return 0;
}
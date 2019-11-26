/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 15:40:09
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 15:59:55
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    int k1 = coordinates[0][0] - coordinates[1][0];
    int k2 = coordinates[0][1] - coordinates[1][1];
    for (int i = 2; i < coordinatesSize; i++) {
        if (k2 * (coordinates[i][0] - coordinates[i - 1][0]) != k1 * (coordinates[i][1] - coordinates[i - 1][1])) return false;
    }
    return true;
}

int main() {
    int res = gcd(-5, -3);
    return 0;
}
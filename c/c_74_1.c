/*
 * @Author: AGOGIN
 * @Date: 2019-12-04 11:01:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-04 11:11:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if (matrixSize == 0 || matrixColSize[0] == 0) return false;
    if (matrix[0][0] > target || matrix[matrixSize - 1][matrixColSize[0] - 1] < target) return false;
    int fast = 0, last = matrixSize - 1;
    while (fast <= last) {
        int mid = fast + (last - fast) / 2;
        if (matrix[mid][0] > target) last = mid - 1;
        else if (matrix[mid][0] < target) fast = mid + 1;
        else return true;
    }
    int p = 0, q = matrixColSize[0] - 1;
    while (p <= q) {
        int temp = p + (q - p) / 2;
        if (matrix[last][temp] > target) q = temp - 1;
        else if (matrix[last][temp] < target) p = temp + 1;
        else return true;
    }
    return false;
}

int main() {

    return 0;
}
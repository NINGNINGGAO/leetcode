/*
 * @Author: AGOGIN
 * @Date: 2019-11-07 11:20:09
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-07 17:32:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void QuickSort(int* nums, int begin, int end) {
    if (begin >= end) return;
    int p = begin, q = end;
    int temp = nums[p];
    while (p < q) {
        while (p < q && nums[q] >= temp) q--;
        if (p < q) nums[p] = nums[q];
        while (p < q && nums[p] < temp) p++;
        if (p < q) nums[q] = nums[p];
    }
    nums[p] = temp;
    QuickSort(nums, begin, p - 1);
    QuickSort(nums, p + 1, end);
}
int distance(int* a, int* b, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return res;
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize){
    if (pointsSize < 2) return 0;
    int* arr = malloc(sizeof(int) * pointsSize);
    int res = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = 0; j < pointsSize; j++) {
            arr[j] = distance(points[i], points[j], 2);
        }
        QuickSort(arr, 0, pointsSize - 1);
        int temp = arr[1], countNum = 1;
        for (int k = 2; k < pointsSize; k++) {
            if (arr[k] != temp) {
                if (countNum >= 2) res += countNum * (countNum - 1);
                temp = arr[k];
                countNum = 1;
            } else {
                countNum++;
            }
        }
        if (countNum >= 2) res += countNum * (countNum - 1);
    }
    free(arr);
    return res;
}

int main() {
    int** points = malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) {
        points[i] = malloc(sizeof(int) * 2);
        points[i][0] = i;
        points[i][1] = 0;
    }
    int temp;
    int res = numberOfBoomerangs(points, 3, &temp);
    return 0;
}
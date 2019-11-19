/*
 * @Author: AGOGIN
 * @Date: 2019-11-19 20:14:54
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 20:22:27
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))
int minCostClimbingStairs(int* cost, int costSize){
    int* arr = malloc(sizeof(int) * costSize);
    memset(arr, 0, sizeof(int) * costSize);
    arr[0] = cost[0];
    arr[1] = cost[1];
    for (int i = 2; i < costSize; i++) {
        arr[i] = Min(arr[i - 1], arr[i - 2]) + cost[i];
    }
    int res = Min(arr[costSize - 1], arr[costSize - 2]);
    free(arr);
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 16:25:34
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 16:40:18
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int cmp(const void* a, const void* b) {
    return ((*(int**)a)[0] - (*(int**)a)[1]) - ((*(int**)b)[0] - (*(int**)b)[1]);
}
int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int res = 0;
    for (int i = 0; i < costsSize; i++) {
        res += costs[i][1];
    }
    qsort(costs, costsSize, sizeof(int*), cmp);
    for (int i = 0; i < costsSize / 2; i++) {
        res += (costs[i][0] - costs[i][1]);
    }
    return res;
}

int main() {

    return 0;
}
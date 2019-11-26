/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 17:44:53
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 21:38:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int temp[10][10] = {0};
    for (int i = 0; i < dominoesSize; i++) {
        temp[dominoes[i][0]][dominoes[i][1]]++;
    }
    int res = 0;
    int mid;
    for (int i = 1; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (i != j) mid = temp[i][j] + temp[j][i];
            else mid = temp[i][j];
            res += (mid - 1) * mid / 2;
        }
    }
    return res;
}

int main() {
    int a[][2] = {{1,1},{1,1},{1,1},{5,6}};
    int n = 4;
    int m[] = {2,2,2,2};
    int** arr = malloc(sizeof(int*) * 4);
    arr[0] = a[0];
    arr[1] = a[1];
    arr[2] = a[2];
    arr[3] = a[3];
    int res = numEquivDominoPairs(arr, n, m);
    return 0;
}
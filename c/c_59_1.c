/*
 * @Author: AGOGIN
 * @Date: 2019-12-02 17:46:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-02 18:13:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    if (n == 0) return NULL;
    *returnColumnSizes = malloc(sizeof(int) * n);
    int** res = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        res[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int flag[4] = {0, n - 1, 0, n - 1};
    int num = 1;
    while (true) {
        for (int i = flag[0]; i <= flag[1]; i++) {
            res[flag[2]][i] = num++;
        }
        flag[2]++;
        if (flag[2] > flag[3]) break;
        for (int i = flag[2]; i <= flag[3]; i++) {
            res[i][flag[1]] = num++;
        }
        flag[1]--;
        if (flag[1] < flag[0]) break;
        for (int i = flag[1]; i >= flag[0]; i--) {
            res[flag[3]][i] = num++;
        }
        flag[3]--;
        if (flag[3] < flag[2]) break;
        for (int i = flag[3]; i >= flag[2]; i--) {
            res[i][flag[0]] = num++;
        }
        flag[0]++;
        if (flag[0] > flag[1]) break;
    }
    return res;
}

int main() {
    int n = 3;
    int p;
    int* q;
    int** res = generateMatrix(n, &p, &q);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-30 14:02:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-30 15:12:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define maxSize 1024
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isTrue(int n, int** flag, int row, int col) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += flag[row][i];
        res += flag[i][col];
    }
    int i = row, j = col;
    while (i >= 0 && j >= 0) res += flag[i--][j--];
    i = row, j = col;
    while (i < n && j < n) res += flag[i++][j++];
    i = row, j = col;
    while (i >= 0 && j < n) res += flag[i--][j++];
    i = row, j = col;
    while (i < n && j >= 0) res += flag[i++][j--];
    if (res == 0) return true;
    else return false;
}
void resCopy(int n, char*** res, int** flag, int* returnSize) {
    res[*returnSize] = malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        res[*returnSize][i] = malloc(sizeof(char) * (n + 1));
        memset(res[*returnSize][i], 0, sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++) {
            if (flag[i][j] == 0) res[*returnSize][i][j] = '.';
            else res[*returnSize][i][j] = 'Q';
        }
    }
    (*returnSize)++;
}
bool backTrack(int n, char*** res, int** flag, int* returnSize, int num) {
    if (num == n) {
        resCopy(n, res, flag, returnSize);
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (isTrue(n, flag, num, i)) {
            flag[num][i] = 1;
            backTrack(n, res, flag, returnSize, num + 1);
            flag[num][i] = 0;
        }
    }
    return false;
}
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * maxSize);
    for (int i = 0; i < maxSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    char*** res = malloc(sizeof(char**) * maxSize);
    int** flag = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        flag[i] = malloc(sizeof(int) * n);
        memset(flag[i], 0, sizeof(int) * n);
    }
    backTrack(n ,res, flag, returnSize, 0);
    free(flag);
    return res;
}

int main() {

    return 0;
}
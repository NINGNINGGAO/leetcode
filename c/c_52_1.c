/*
 * @Author: AGOGIN
 * @Date: 2019-11-30 14:59:48
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-30 15:12:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define maxSize 1024
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
bool backTrack(int n, int* res, int** flag, int num) {
    if (num == n) {
        (*res)++;
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (isTrue(n, flag, num, i)) {
            flag[num][i] = 1;
            backTrack(n, res, flag, num + 1);
            flag[num][i] = 0;
        }
    }
    return false;
}
int totalNQueens(int n){
    int res = 0;
    int** flag = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        flag[i] = malloc(sizeof(int) * n);
        memset(flag[i], 0, sizeof(int) * n);
    }
    backTrack(n, &res, flag, 0);
    free(flag);
    return res;
}

int main() {

    return 0;
}
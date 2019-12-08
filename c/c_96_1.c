/*
 * @Author: AGOGIN
 * @Date: 2019-12-07 22:25:23
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-07 22:31:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int numTrees(int n){
    int* arr = malloc(sizeof(int) * (n + 1));
    memset(arr, 0, sizeof(int) * (n + 1));
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            arr[i] += arr[j - 1] * arr[i - j];
        }
    }
    int res = arr[n];
    free(arr);
    return res;
}

int main() {

    return 0;
}
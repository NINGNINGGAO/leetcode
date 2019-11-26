/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 17:03:00
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 17:05:21
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int tribonacci(int n){
    int* arr = malloc(sizeof(int) * (37 + 1));
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    if (n <= 2) return arr[n];
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
}

int main() {

    return 0;
}
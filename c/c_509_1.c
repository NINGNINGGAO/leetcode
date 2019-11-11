/*
 * @Author: AGOGIN
 * @Date: 2019-11-11 19:42:53
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-11 19:48:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int fib(int N){
    int result[] = {0,1};
    if (N < 2) return result[N];
    int* res = malloc(sizeof(int) * (N + 1));
    res[0] = 0;
    res[1] = 1;
    for (int i = 2; i <= N; i++) {
        res[i] = res[i - 2] + res[i - 1];
    }
    return res[N];
}

int main() {

    return 0;
}
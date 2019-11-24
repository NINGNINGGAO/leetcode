/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 11:23:14
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 11:50:26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int numPairsDivisibleBy60(int* time, int timeSize){
    int arr[60] = {0};
    for (int i = 0; i < timeSize; i++) {
        arr[time[i] % 60]++;
    }
    int res = (arr[0] * (arr[0] - 1) + arr[30] * (arr[30] - 1)) >> 1;
    for (int i = 1; i < 30; i++) {
        res += arr[i] * arr[60 - i];
    }
    return res;
}

int main() {

    return 0;
}
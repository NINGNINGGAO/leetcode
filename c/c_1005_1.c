/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 10:46:47
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 10:53:20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int largestSumAfterKNegations(int* A, int ASize, int K){
    int arr[201] = {0};
    for (int i = 0; i < ASize; i++) {
        arr[A[i] + 100]++;
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 201; j++) {
            if (arr[j] != 0) {
                arr[j]--;
                arr[200 - j]++;
                break;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 201; i++) {
        while (arr[i] != 0) {
            res += (i - 100);
            arr[i]--;
        }
    }
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-26 10:38:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-26 15:15:06
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int numPrimeArrangements(int n){
    int* temp = malloc(sizeof(int) * (n + 1));
    memset(temp, 0, sizeof(int) * (n + 1));
    for (int i = 2; i < n / 2 + 1; i++) {
        if (temp[i] == 0) {
            for (int j = i * 2; j <= n; j += i) {
                temp[j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (temp[i] == 0) count++;
    }
    long long temp1 = 1, temp2 = 1;
    for (int i = 1; i <= count; i++) {
        temp1 = (temp1 * i) % 1000000007;
    }
    for (int i = 1; i <= n - count; i++) {
        temp2 = (temp2 * i) % 1000000007;
    }
    return (temp1 * temp2) % 1000000007;
}

int main() {

    return 0;
}
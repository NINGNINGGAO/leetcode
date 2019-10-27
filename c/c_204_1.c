/*
 * @Author: AGOGIN
 * @Date: 2019-10-27 17:05:14
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-27 18:25:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int countPrimes(int n){
    if (n <= 2) return 0;
    int flag[n];
    memset(flag, 0, sizeof(flag));
    for (int i = 2; i * i < n; i++) {
        if (flag[i] == 0) {
            for (int j = i * i; j < n; j += i) {
                flag[j] = 1;
            }
        }
    }
    int ret = 0;
    for (int i = 2; i < n; i++) {
        if (flag[i] == 0) {
            ret++;
        }
    }
    return ret;
}

int main() {
    int res = countPrimes(10);
    printf("%d\n", res);
    return 0;
}
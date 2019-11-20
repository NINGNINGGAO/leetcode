/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 09:59:24
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 10:20:28
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int countPrimeSetBits(int L, int R){
    int primes[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
    int res = 0;
    int count = 0;
    for (int i = L; i <= R; i++) {
        count = 0;
        int n = i;
        while (n != 0) {
            n &= (n - 1);
            count++;
        }
        res += primes[count];
    }
    return res;
}

int main() {
    int res = countPrimeSetBits(6,10);
    return 0;
}
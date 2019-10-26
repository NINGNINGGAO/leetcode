/*
 * @Author: AGOGIN
 * @Date: 2019-10-26 17:18:33
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-26 17:43:20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int hammingWeight(uint32_t n) {
    int res = 0;
    while (n != 0) {
        res++;
        n -= lowbit(n);
    }
    return res;
}
int lowbit(uint32_t x) {
    return x & -x;
}

int main() {

    return 0;
}
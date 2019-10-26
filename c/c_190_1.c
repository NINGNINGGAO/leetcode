/*
 * @Author: AGOGIN
 * @Date: 2019-10-26 17:16:11
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-26 17:18:24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res <<= 1;
        res += n & 1;
        n >>= 1;
    }
    return res;
}

int main() {

    return 0;
}
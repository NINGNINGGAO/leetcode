/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 11:20:21
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 11:21:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int bitwiseComplement(int N){
    unsigned m = 2;
    while (m <= N) m <<= 1;
    return m - N - 1;
}

int main() {

    return 0;
}
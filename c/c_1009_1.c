/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 10:54:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 11:17:38
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
int bitwiseComplement(int N){
    if (N == 0) return 1;
    unsigned int m = N;
    while ((m & (m - 1)) != 0) m &= (m - 1);
    m = (m << 1) - 1;
    return ~N & m;
}

int main() {
    int n = 0;
    int res = bitwiseComplement(n);
    return 0;
}
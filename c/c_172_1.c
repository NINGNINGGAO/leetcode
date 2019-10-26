/*
 * @Author: AGOGIN
 * @Date: 2019-10-26 13:28:16
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-26 13:31:16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int trailingZeroes(int n){
    int ret = 0;
    while (n >= 5) {
        ret += n / 5;
        n /= 5;
    }
    return ret;
}

int main() {

    return 0;
}
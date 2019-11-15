/*
 * @Author: AGOGIN
 * @Date: 2019-08-18 16:54:12
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-08-18 16:54:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}



int divide(int dividend, int divisor){
    if (dividend == 0) return 0;
    int flag = (dividend ^ divisor) >= 0 ? 0 : 1;
    if (divisor > 0) divisor = -divisor;
    if (dividend > 0) dividend = -dividend;
    if (dividend > divisor) return 0;
    int ret = 0;
    int temp, mid;
    while (dividend != 0) {
        temp = divisor;
        mid = 1;
        if (dividend > divisor) break;
        while (dividend - temp < temp) {
            temp = -temp;
            temp <<= 1;
            mid <<= 1;
            temp = -temp;
        }
        ret += -mid;
        dividend -= temp;
    }
    if (flag == 0) {
        if (ret == INT_MIN) return INT_MAX;
        return -ret;
    }
    return ret;
}

main() {
    int dividend = 1;
    int divisor = 1;
    printf("%d\n", divide(dividend, divisor));
}
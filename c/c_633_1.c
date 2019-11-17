/*
 * @Author: AGOGIN
 * @Date: 2019-11-16 15:55:59
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-16 16:36:57
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
bool judgeSquareSum(int c){
    for (int i = 2; i * i <= c; i++) {
        int count = 0;
        if (c % i == 0) {
            while (c % i == 0) {
                count++;
                c /= i;
            }
        }
        if (i % 4 == 3 && count % 2 != 0) return false;
    }
    return c % 4 != 3;
}

int main() {
    bool res = judgeSquareSum(9);
    return 0;
}
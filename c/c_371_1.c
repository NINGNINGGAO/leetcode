/*
 * @Author: AGOGIN
 * @Date: 2019-11-04 09:58:16
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-04 10:35:25
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int getSum(int a, int b){
        unsigned int c = a;
        unsigned int d = b;
        while (d > 0) {
            unsigned int carry = c & d;
            c = c ^ d;
            d = carry << 1;
        }
        return (int)c;
}

int main() {

    return 0;
}
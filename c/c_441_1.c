/*
 * @Author: AGOGIN
 * @Date: 2019-11-07 09:40:11
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-07 10:04:09
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
int arrangeCoins(int n){
    return (int)(sqrt(2.0) * sqrt(n + 0.125)  - 0.5);
}

int main() {

    return 0;
}
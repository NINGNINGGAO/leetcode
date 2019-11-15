/*
 * @Author: AGOGIN
 * @Date: 2019-10-27 14:35:18
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:38:21
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int bitSquareSum(int n) {
    int sum = 0;
    int bit;
    while (n > 0) {
        bit = n % 10;
        sum += bit * bit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n){
    int fast = n, slow = n;
    do {
        slow = bitSquareSum(slow);
        fast = bitSquareSum(fast);
        fast = bitSquareSum(fast);
    } while (slow != fast);
    return fast == 1;
}

int main() {

    return 0;
}
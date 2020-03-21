/*
 * @Author: AGOGIN 
 * @Date: 2020-03-21 12:03:54 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-21 12:09:56
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

bool canMeasureWater(int x, int y, int z){
    if (x + y < z) return false;
    if (x == 0 || y == 0) return z == 0 || x + y == z;
    return z % gcd(x, y) == 0;
}

int main() {
    
    return 0;
}
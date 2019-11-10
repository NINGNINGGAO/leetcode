/*
 * @Author: AGOGIN
 * @Date: 2019-11-10 16:11:46
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-10 16:17:04
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int findComplement(int num){
    unsigned int n = num;
    while ((n & (n - 1)) != 0) n &= (n - 1);
    n = (n << 1) - 1;
    return num ^ n;
}

int main() {
    int res = findComplement(6);
    return 0;
}
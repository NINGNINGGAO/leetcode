/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 16:19:46
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 17:13:21
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool hasAlternatingBits(int n){
    unsigned int num = n;
    num ^= (num >> 1);
    return !(num & (num + 1));
}

int main() {

    return 0;
}
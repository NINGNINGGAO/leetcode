/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 21:49:03
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 21:49:49
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isPowerOfFour(int num){
    return num > 0 && (num & num - 1) == 0 && (num & 0x55555555) == num;
}

int main() {

    return 0;
}
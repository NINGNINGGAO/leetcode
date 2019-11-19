/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 22:17:19
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 23:00:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isOneBitCharacter(int* bits, int bitsSize){
    if (bitsSize < 2) return true;
    if (bits[bitsSize - 2] == 0) return true;
    int i = 0;
    while (i < bitsSize - 1) {
        if (bits[i] == 0) i++;
        else {
            i += 2;
        }
    }
    if (i == bitsSize) return false;
    return true;
}

int main() {

    return 0;
}
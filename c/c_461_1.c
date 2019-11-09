/*
 * @Author: AGOGIN
 * @Date: 2019-11-09 16:19:04
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-09 16:27:44
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int hammingDistance(int x, int y){
    int temp = x ^ y;
    int res = 0;
    while (temp != 0) {
        temp = temp & (temp - 1);
        res++;
    }
    return res;
}

int main() {
    int res = hammingDistance(1, 4);
    return 0;
}
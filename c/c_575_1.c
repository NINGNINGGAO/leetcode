/*
 * @Author: AGOGIN
 * @Date: 2019-11-14 22:32:13
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-14 22:35:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int distributeCandies(int* candies, int candiesSize){
    qsort(candies, candiesSize, sizeof(int), cmp);
    int res = 1;
    int flag = candies[0];
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] != candies[i - 1]) res++;
    }
    if (res > candiesSize / 2) return candiesSize / 2;
    else return res;
}

int main() {

    return 0;
}
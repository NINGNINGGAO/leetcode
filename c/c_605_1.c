/*
 * @Author: AGOGIN
 * @Date: 2019-11-16 10:21:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-16 10:53:50
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int countZeros = 0;
    int res = 0;
    countZeros += flowerbed[0] == 1 ? 0 : 1;
    for (int i = 1; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0 && flowerbed[i - 1] != 1) {
            countZeros++;
        } else if (flowerbed[i] == 1 && flowerbed[i - 1] == 0) {
            res += countZeros / 2;
            countZeros = 0;
        }
    }
    res += (countZeros + 1) / 2;
    return res >= n;
}

int main() {
    int nums[] = {1,0,0,0,1,0,0};
    int numsSize = sizeof(nums) / sizeof(int);
    int n = 2;
    bool res = canPlaceFlowers(nums, numsSize, 2);
    return 0;
}
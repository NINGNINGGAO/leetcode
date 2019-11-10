/*
 * @Author: AGOGIN
 * @Date: 2019-11-10 13:38:39
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-10 16:09:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define abs(a) ((a) > 0 ? (a) : (-(a)))
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
bool isSort(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) return false;
    }
    return true;
}
int cmp (const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    if (isSort(houses, housesSize) == false) {
        qsort(houses, housesSize, sizeof(int), cmp);
    }
    if (isSort(heaters, heatersSize) == false) {
        qsort(heaters, heatersSize, sizeof(int), cmp);
    }
    int res = INT_MIN;
    int fir = 0, sec = 1;
    int mid = 0;
    int temp;
    for (int i = 0; i < housesSize; i++) {
        while (mid < heatersSize - 1 && heaters[mid] < houses[i]) mid++;
        if (mid == 0) {
            temp = abs(heaters[mid] - houses[i]);
        } else {
            temp = Min(abs(heaters[mid] - houses[i]), abs(heaters[mid - 1] - houses[i]));
        }
        res = Max(res, temp);
    }
    return res;
}

int main() {
    int a[] = {1,2,3,4};
    int b[] = {1,4};
    int aNum = sizeof(a) / sizeof(int);
    int bNum = sizeof(b) / sizeof(int);
    int res = findRadius(a, aNum, b, bNum);
    return 0;
}
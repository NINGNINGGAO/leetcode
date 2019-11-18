/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 17:13:13
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 17:34:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Nums {
    int begin;
    int len;
    int fre;
};
int findShortestSubArray(int* nums, int numsSize){
    struct Nums* arr = malloc(sizeof(struct Nums) * 50000);
    memset(arr, 0, sizeof(struct Nums) * 50000);
    for (int i = 0; i < numsSize; i++) {
        if (arr[nums[i]].fre == 0) {
            arr[nums[i]].begin = i;
            arr[nums[i]].len = 1;
        } else arr[nums[i]].len = i - arr[nums[i]].begin + 1;
        (arr[nums[i]].fre)++;
    }
    int maxFre = 0, minLen;
    for (int i = 0; i < 50000; i++) {
        if (arr[i].fre > maxFre) {
            maxFre = arr[i].fre;
            minLen = arr[i].len;
        } else if (arr[i].fre == maxFre && arr[i].len < minLen) minLen = arr[i].len;
    }
    return minLen;
}

int main() {
    int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(int);
    int res = findShortestSubArray(nums, numsSize);
    return 0;
}
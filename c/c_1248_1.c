/*
 * @Author: AGOGIN 
 * @Date: 2020-04-21 10:34:14 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-21 12:20:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int numberOfSubarrays(int* nums, int numsSize, int k){
    int* arr = malloc(sizeof(int) * (numsSize + 2));
    int arrSize = 0;
    arr[arrSize++] = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 1) arr[arrSize++] = i;
    }
    arr[arrSize++] = numsSize;
    int ret = 0;
    if (arrSize - 2 < k) return ret;
    for (int i = 1; i < arrSize - k; i++) {
        ret += (arr[i] - arr[i - 1]) * (arr[i + k] - arr[i + k - 1]);
    }
    free(arr);
    return ret;
}

int main() {
    int nums[] = {1,1,2,1,1};
    int numsSize = sizeof(nums) / sizeof(int);
    int k = 3;
    int ret = numberOfSubarrays(nums, numsSize, k);
    printf("%d\n", ret);
    return 0;
}
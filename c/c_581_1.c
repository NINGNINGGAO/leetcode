/*
 * @Author: AGOGIN
 * @Date: 2019-11-14 22:35:44
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-14 22:44:39
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int findUnsortedSubarray(int* nums, int numsSize){
    int* arr = malloc(sizeof(int) * numsSize);
    for (int  i = 0; i < numsSize; i++) arr[i] = nums[i];
    qsort(arr, numsSize, sizeof(int), cmp);
    int fast = 0, last = numsSize - 1;
    while (fast < last && arr[fast] == nums[fast]) fast++;
    while (fast < last && arr[last] == nums[last]) last--;
    if (last == fast) return 0;
    return last - fast + 1;
}

int main() {
    int nums[] = {1,2,4,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int res = findUnsortedSubarray(nums, numsSize);
    printf("%d\n", res);
    return 0;
}
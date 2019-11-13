/*
 * @Author: AGOGIN
 * @Date: 2019-11-13 09:51:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-13 10:13:35
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int findPairs(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    int j;
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        j = i + 1;
        while (j < numsSize && nums[j] < nums[i] + k) j++;
        if (j < numsSize && nums[j] == nums[i] + k) res++;
    }
    return res;
}
int main() {
    int nums[] = {1,1,3,4,5};
    int numsSize = sizeof(nums) / sizeof(int);
    int k = 0;
    int res = findPairs(nums, numsSize, k);
    return 0;
}
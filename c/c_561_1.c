/*
 * @Author: AGOGIN
 * @Date: 2019-11-14 09:37:57
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-14 09:44:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}
int arrayPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = 0;
    for (int i = 0; i < numsSize; i += 2) {
        res += nums[i];
    }
    return res;
}

int main() {
    int nums[] = {4,2,1,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int res = arrayPairSum(nums, numsSize);
    printf("%d\n", res);
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-10-26 13:33:30
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-26 16:47:16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

void reverse(int* nums, int p, int q) {
    int temp;
    while (p < q) {
        temp = nums[p];
        nums[p] = nums[q];
        nums[q] = temp;
        p++;
        q--;
    }
}

int main() {

    return 0;
}
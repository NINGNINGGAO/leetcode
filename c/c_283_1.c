/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 12:10:07
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 12:17:08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void moveZeroes(int* nums, int numsSize){
    int slow = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[slow++] = nums[i];
        }
    }
    for (int i = slow; i < numsSize; i++) {
        nums[i] = 0;
    }
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 17:46:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 17:56:26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool checkPossibility(int* nums, int numsSize){
    if (numsSize <= 0) return true;
    int count = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            int temp = nums[i];
            if (i > 0) {
                nums[i] = nums[i - 1];
            } else {
                nums[i] = nums[i + 1];
            }
            if (nums[i] > nums[i + 1]) {
                nums[i] = temp;
                nums[i + 1] = temp;
            }
            count++;
            if (count > 1) return false;
        }
    }
    return true;
}

int main() {

    return 0;
}
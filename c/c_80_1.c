/*
 * @Author: AGOGIN
 * @Date: 2019-12-06 17:09:35
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-06 18:46:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2) return numsSize;
    int fast = 2, slow = 1;
    while (fast < numsSize) {
        if (nums[fast] != nums[slow - 1]) {
            nums[++slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}

int main() {

    return 0;
}
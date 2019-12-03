/*
 * @Author: AGOGIN
 * @Date: 2019-12-02 16:36:21
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-02 17:25:06
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool canJump(int* nums, int numsSize){
    int bound = 0;
    int maxPosition = 0;
    int i = 0;
    while (i <= bound) {
        maxPosition = maxPosition > (nums[i] + i) ? maxPosition : (nums[i] + i);
        if (i == bound) bound = maxPosition < (numsSize - 1) ? maxPosition : (numsSize - 1);
        i++;
    }
    if (maxPosition < numsSize - 1) return false;
    else return true;
}

int main() {

    return 0;
}
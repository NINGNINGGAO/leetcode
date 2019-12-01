/*
 * @Author: AGOGIN
 * @Date: 2019-12-01 10:52:58
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 11:01:01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int jump(int* nums, int numsSize){
    int res = 0;
    int bound = 0;
    int maxPosition = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        maxPosition = maxPosition > (nums[i] + i) ? maxPosition : (nums[i] + i);
        if (i == bound) {
            bound = maxPosition;
            res++;
        }
    }
    return res;
}

int main() {

    return 0;
}
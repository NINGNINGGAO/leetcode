/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 15:25:13
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-12-05 15:25:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void sortColors(int* nums, int numsSize){
    int p = 0, q = numsSize - 1, cur = 0;
    while (cur <= q) {
        if (nums[cur] == 2) {
            int temp = nums[cur];
            nums[cur] = nums[q];
            nums[q] = temp;
            q--;
        } else if (nums[cur] == 0) {
            int temp = nums[cur];
            nums[cur] = nums[p];
            nums[p] = temp;
            p++;
            cur++;
        } else {
            cur++;
        }
    }
}

int main() {

    return 0;
}
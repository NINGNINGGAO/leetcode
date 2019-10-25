/*
 * @Author: AGOGIN
 * @Date: 2019-10-25 19:44:39
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-25 19:47:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int majorityElement(int* nums, int numsSize){
    if (numsSize <= 0) return NULL;
    if (numsSize == 1) return *nums;
    int candidata = nums[0], count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == candidata) {
            count++;
        } else {
            if (count == 1) {
                candidata = nums[i];
            } else {
                count--;
            }
        }
    }
    return candidata;
}

int main() {

    return 0;
}
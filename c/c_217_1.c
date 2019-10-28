/*
 * @Author: AGOGIN
 * @Date: 2019-10-28 09:39:05
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-28 10:21:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Sort(int* nums, int begin, int end) {
    if (begin < end) {
        int i = begin + 1;
        int j = end;
        while (i < j) {
            if (nums[i] > nums[begin]) {
                swap(&nums[i], &nums[j]);
                j--;
            } else {
                i++;
            }
        }
        if (nums[i] >= nums[begin]) {
            i--;
        }
        swap(&nums[begin], &nums[i]);
        Sort(nums, begin, i);
        Sort(nums, j, end);
    }
}

bool containsDuplicate(int* nums, int numsSize){
    Sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {

    return 0;
}
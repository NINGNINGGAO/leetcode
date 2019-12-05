/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 15:26:54
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-12-05 15:26:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool search(int* nums, int numsSize, int target){
    if (numsSize == 0) return false;
    int start = 0, end = numsSize - 1, mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (nums[mid] == target) return true;
        if (nums[start] == nums[mid]) {
            start++;
            continue;
        }
        if (nums[start] < nums[mid]) {
            if (nums[mid] > target && nums[start] <= target) end = mid - 1;
            else start = mid + 1;
        } else {
            if (nums[mid] < target && nums[end] >= target) start = mid + 1;
            else end = mid - 1;
        }
    }
    return false;
}

int main() {

    return 0;
}
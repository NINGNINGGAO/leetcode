/*
 * @Author: AGOGIN
 * @Date: 2019-11-27 09:41:34
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-27 10:07:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int search(int* nums, int numsSize, int target){
    if (numsSize == 0) return -1;
    if (numsSize == 1) {
        if (nums[0] == target) return 0;
        else return -1;
    }
    int fast = 0, last = numsSize - 1;
    int mid;
    while (fast <= last) {
        mid = fast + (last - fast) / 2;
        if (mid < numsSize - 1 && nums[mid] > nums[mid + 1]) {
            break;
        } else if ((mid == numsSize - 1 || nums[mid] < nums[mid + 1])&& nums[mid] >= nums[0]) fast = mid + 1;
        else if (nums[mid] < nums[mid + 1] && nums[mid] < nums[0]) last = mid - 1;
    }
    if (target > nums[0]) {
        fast = 0;
        last = mid;
    } else if (target < nums[0]) {
        fast = mid + 1;
        last = numsSize - 1;
    } else {
        return 0;
    }
    while (fast <= last) {
        mid = fast + (last - fast) / 2;
        if (nums[mid] > target) last = mid - 1;
        else if (nums[mid] < target) fast = mid + 1;
        else return mid;
    }
    return -1;
}

int main() {
    int nums[] = {1,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int n = 0;
    int res = search(nums, numsSize, n);
    return 0;
}
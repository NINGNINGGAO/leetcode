/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 21:40:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 21:48:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int search(int* nums, int numsSize, int target){
    int fast = 0, last = numsSize - 1;
    while (fast <= last) {
        int mid = fast + (last - fast) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            last = mid - 1;
        } else {
            fast = mid + 1;
        }
    }
    return -1;
}

int main() {

    return 0;
}
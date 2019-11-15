/*
 * @Author: AGOGIN
 * @Date: 2019-10-18 13:48:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:41:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}

int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
        else return mid;
    }
    return left;
}

int main() {

    return 0;
}
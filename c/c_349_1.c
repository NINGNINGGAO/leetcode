/*
 * @Author: AGOGIN
 * @Date: 2019-11-03 16:09:10
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-03 16:47:24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void swap(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
void Sort(int* nums, int p, int q) {
    if (p < q) {
        int i = p + 1, j = q;
        while (i < j) {
            if (nums[i] > nums[p]) {
                swap(&nums[i], &nums[j]);
                j--;
            } else {
                i++;
            }
        }
        if (nums[i] >= nums[p]) i--;
        swap(&nums[p], &nums[i]);
        Sort(nums, p, i);
        Sort(nums, j, q);
    }
}
void delrepeat(int* nums, int* numsSize) {
    int mid = 0;
    for (int i = 1; i < *numsSize; i++) {
        if (nums[i] != nums[mid]) {
            mid++;
            nums[mid] = nums[i];
        }
    }
    *numsSize = mid + 1;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = 0;
    if (nums1Size == 0 || nums2Size == 0) return NULL;
    Sort(nums1, 0, nums1Size - 1);
    Sort(nums2, 0, nums2Size - 1);
    delrepeat(nums1, &nums1Size);
    delrepeat(nums2, &nums2Size);
    int* res = malloc(sizeof(int) * 521);
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] > nums2[j]) {
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            res[(*returnSize)++] = nums1[i];
            i++;
            j++;
        }
    }
    return res;
}

int main() {
    int nums1[] = {1,2,2,1};
    int nums2[] = {2,2};
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2Size = sizeof(nums2) / sizeof(int);
    int returnSize;
    int* res = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
    return 0;
}
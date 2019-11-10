/*
 * @Author: AGOGIN
 * @Date: 2019-11-10 17:40:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-10 17:45:50
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = nums1Size;
    if (nums1Size == 0) return NULL;
    int* res = malloc(sizeof(int) * nums1Size);
    for (int i = 0; i < nums1Size; i++) {
        int j = 0;
        while (nums1[i] != nums2[j]) j++;
        j++;
        while (j < nums2Size && nums2[j] <= nums1[i]) j++;
        if (j < nums2Size) res[i] = nums2[j];
        else res[i] = -1;
    }
    return res;
}

int main() {

    return 0;
}
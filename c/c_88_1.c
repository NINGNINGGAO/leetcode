/*
 * @Author: AGOGIN
 * @Date: 2019-10-17 20:49:43
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-17 21:57:03
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p, q, r;
    p = m - 1;
    q = n - 1;
    r = n + m - 1;
    while (p >= 0 && q >= 0) {
        if (nums1[p] > nums2[q]) {
            nums1[r--] = nums1[p--];
        } else {
            nums1[r--] = nums2[q--];
        }
    }
    if (p == -1) {
        while (q >= 0) {
            nums1[r--] = nums2[q--];
        }
    }
}

int main() {

    return 0;
}
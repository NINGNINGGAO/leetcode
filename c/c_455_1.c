/*
 * @Author: AGOGIN
 * @Date: 2019-11-08 16:34:13
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-08 16:52:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void quickSort(int* nums, int begin, int end) {
    if (begin >= end) return;
    int temp = nums[begin];
    int p = begin, q = end;
    while (p < q) {
        while (p < q && nums[q] >= temp) q--;
        if (p < q) nums[p] = nums[q];
        while (p < q && nums[p] < temp) p++;
        if (p < q) nums[q] = nums[p];
    }
    nums[p] = temp;
    quickSort(nums, begin, p - 1);
    quickSort(nums, p + 1, end);
}
int findContentChildren(int* g, int gSize, int* s, int sSize){
    quickSort(g, 0, gSize - 1);
    quickSort(s, 0, sSize - 1);
    int i = 0, j = 0;
    int res = 0;
    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            res++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return res;
}

int main() {

    return 0;
}
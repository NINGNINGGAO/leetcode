/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 09:37:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 09:44:56
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int peakIndexInMountainArray(int* A, int ASize){
    int fast = 0, last = ASize - 1;
    int mid;
    while (fast <= last) {
        mid = fast + (last - fast) / 2;
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
            return mid;
        } else if (A[mid] > A[mid - 1]) {
            fast = mid + 1;
        } else if (A[mid] > A[mid + 1]) {
            last = mid - 1;
        }
    }
    return -1;
}

int main() {
    int num[] = {18,29,38,59,98,100,99,98,90};
    int a = sizeof(num) / sizeof(int);
    int res = peakIndexInMountainArray(num, a);
    return 0;
}
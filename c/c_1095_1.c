/*
 * @Author: AGOGIN 
 * @Date: 2020-04-29 20:50:31 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-29 21:58:47
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */
int searchMountain(MountainArray* mountainArr, int target, int front, int cen, int after) {
    int mid, midValue;
    int fast = front, last = cen;
    while (fast <= last) {
        mid = (fast + last) / 2;
        midValue = get(mountainArr, mid);
        if (midValue == target) return mid;
        else if (midValue < target) fast = mid + 1;
        else last = mid - 1;
    }
    fast = cen + 1, last = after;
    while (fast <= last) {
        mid = (fast + last) / 2;
        midValue = get(mountainArr, mid);
        if (midValue ==  target) return mid;
        else if (midValue < target) last = mid - 1;
        else fast = mid + 1;
    }
    return -1;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
	int arrSize = length(mountainArr);
    int fast = 0, last = arrSize - 1, mid;
    int front, after;
    while (fast < last) {
        mid = (fast + last) / 2;
        if (get(mountainArr, mid) < get(mountainArr, mid + 1)) fast = mid + 1;
        else last = mid;
    }
    return searchMountain(mountainArr, target, 0, fast, arrSize - 1);
}

int main() {
    
    return 0;
}
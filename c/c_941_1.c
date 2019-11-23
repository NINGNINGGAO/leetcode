/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 12:45:09
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 13:48:37
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool validMountainArray(int* A, int ASize){
    if (ASize < 3) return false;
    int fast = 1, last = ASize - 2;
    while (fast < ASize && A[fast] > A[fast - 1]) fast++;
    while (last >= 0 && A[last] > A[last + 1]) last--;
    fast--;
    last++;
    if (fast == ASize - 1 || last == 0 || last != fast) return false;
    return true;
}

int main() {
    int nums[] = {0,3,2,1};
    int numsSize = sizeof(nums) / sizeof(int);
    bool res = validMountainArray(nums, numsSize);
    return 0;
}
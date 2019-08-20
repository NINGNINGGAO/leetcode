/*
 * @Author: AGOGIN 
 * @Date: 2019-08-20 16:41:38 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-08-20 17:17:39
 */

#include <stdio.h>
#include <stdlib.h>

void ShellSort_1(int* nums, int numsSize) {
    int i, j, temp;
    int* p;
    int interval[] = {		// Sedgewick增量
          1073643521, 603906049, 268386305, 150958081, 67084289,
          37730305, 16764929, 9427969, 4188161, 2354689,
          1045505, 587521, 260609, 146305, 64769,
          36289, 16001, 8929, 3905, 2161,
          929, 505, 209, 109, 41,
          19, 5, 1, 0};
    for (p = interval; *p > numsSize; p++);
    while (*p != 0) {
        for (i = *p; i < numsSize; i++) {
            temp = nums[i];
            for (j = i - *p; j >= 0 && nums[j] > temp; j -= *p) {
                nums[j + *p] = nums[j];
                nums[j] = temp;
            }
        }
        p++;
    }
}

void nextPermutation(int* nums, int numsSize){
    int flag = 0;
    int i, j;
    int temp, mid;
    for (i = numsSize - 2; i >= 0; i--) {
        if (nums[i + 1] > nums[i]) {
            for (j = i +1; j < numsSize; j++) {
                if (nums[j] <= nums[i]) {
                    break;
                }
            }
            temp = nums[j - 1];
            nums[j - 1] = nums[i];
            nums[i] = temp;
            ShellSort_1(&(nums[i + 1]), numsSize - (i + 1));
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        for (int k = 0; k < numsSize / 2; k++) {
            mid = nums[k];
            nums[k] = nums[numsSize - 1 - k];
            nums[numsSize - 1 - k] = mid;
        }
    }
}

main() {
    int nums[] = {1,5,1};
    int numsSize = sizeof(nums)/sizeof(int);
    nextPermutation(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}
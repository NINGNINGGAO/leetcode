/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 16:46:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 17:00:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize = num_people;
    int* res = malloc(sizeof(int) * num_people);
    memset(res, 0, sizeof(int) * num_people);
    int count = 1, mid = 0;
    while (candies != 0) {
        if (candies > count) {
            res[mid] += count;
            candies -= count;
            count++;
        } else {
            res[mid] += candies;
            candies = 0;
        }
        mid++;
        mid %= num_people;
    }
    return res;
}

int main() {

    return 0;
}
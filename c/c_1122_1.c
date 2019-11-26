/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 17:20:35
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 17:35:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Node {
    int val;
    int num;
    int s;
};
int cmp(const void* a, const void* b) {
    if (((struct Node*)b)->s == 0 && ((struct Node*)a)->s == 0) {
        return ((struct Node*)a)->val - ((struct Node*)a)->val;
    } else if (((struct Node*)b)->s == 0) return -1;
    else if (((struct Node*)a)->s == 0) return 1;
    else return ((struct Node*)a)->s - ((struct Node*)b)->s;
}
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    *returnSize = 0;
    int* res = malloc(sizeof(int) * arr1Size);
    int hashSize = 1001;
    struct Node* arrHash = malloc(sizeof(struct Node) * hashSize);
    memset(arrHash, 0, sizeof(struct Node) * 1001);
    for (int i = 0; i < hashSize; i++) {
        arrHash[i].val = i;
    }
    for (int i = 0; i < arr1Size; i++) {
        (arrHash[arr1[i]].num)++;
    }
    for (int i = 0; i < arr2Size; i++) {
        arrHash[arr2[i]].s = i + 1;
    }
    qsort(arrHash, hashSize, sizeof(struct Node), cmp);
    for (int i = 0; i < hashSize; i++) {
        for (int j = 0; j < arrHash[i].num; j++) {
            res[(*returnSize)++] = arrHash[i].val;
        }
    }
    return res;
}

int main() {

    return 0;
}
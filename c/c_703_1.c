/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 19:38:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 21:38:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
typedef struct {
    int* arr;
    int cap;
    int index;
} KthLargest;
void minHeap(KthLargest* obj, int val) {
    if (obj->index < obj->cap) heapSort(obj, val);
    else if (obj->arr[0] < val) {
        int temp = 0;
        int left, right;
        do {
            left = INT_MAX;
            right = INT_MAX;
            if (temp * 2 + 1 < obj->cap) left = obj->arr[temp * 2 + 1];
            if (temp * 2 + 2 < obj->cap) right = obj->arr[temp * 2 + 2];
            if (temp * 2 + 1 < (obj->cap) && left <= right) {
                obj->arr[temp] = left;
                temp = temp * 2 + 1;
            } else if (left > right){
                obj->arr[temp] = right;
                temp = temp * 2 + 2;
            }
        } while (temp * 2 + 1 < obj->cap);
        while (temp > 0 && obj->arr[(temp - 1) / 2] > val) {
            obj->arr[temp] = obj->arr[(temp - 1) / 2];
            temp = (temp - 1) / 2;
        }
        obj->arr[temp] = val;
    }
}
void heapSort(KthLargest* obj, int val) {
    int temp = obj->index;
    while (temp > 0 && obj->arr[(temp - 1) / 2] > val) {
        obj->arr[temp] = obj->arr[(temp - 1) / 2];
        temp = (temp - 1) / 2;
    }
    obj->arr[temp] = val;
    (obj->index)++;
}


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = malloc(sizeof(KthLargest));
    obj->arr = malloc(sizeof(int) * k);
    obj->cap = k;
    obj->index = 0;
    for (int i = 0; i < numsSize; i++) {
        minHeap(obj, nums[i]);
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    minHeap(obj, val);
    return obj->arr[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/

int main() {
    int k = 3;
    int nums[] = {1,1};
    int numsSize = sizeof(nums) / sizeof(int);
    KthLargest* obj = kthLargestCreate(k, nums, numsSize);
    printf("%d\n", kthLargestAdd(obj, 1));
    printf("%d\n", kthLargestAdd(obj, 1));
    printf("%d\n", kthLargestAdd(obj, 3));
    printf("%d\n", kthLargestAdd(obj, 3));
    printf("%d\n", kthLargestAdd(obj, 3));
    printf("%d\n", kthLargestAdd(obj, 4));
    printf("%d\n", kthLargestAdd(obj, 4));
    printf("%d\n", kthLargestAdd(obj, 5));
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 17:50:13
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 20:24:15
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct MaxHeap {
    int* arr;
    int tail;
    int arrSize;
};
struct MaxHeap* createMaxHeap(int maxHeapSize) {
    struct MaxHeap* obj = malloc(sizeof(struct MaxHeap));
    obj->arr = malloc(sizeof(int) * maxHeapSize);
    memset(obj->arr, 0, sizeof(int) * maxHeapSize);
    obj->arrSize = maxHeapSize;
    obj->tail = 0;
    return obj;
}
bool isEmpty(struct MaxHeap* obj) {
    if (obj->tail == 0) return true;
    else return false;
}
void insertMaxHeap(struct MaxHeap* obj, int val) {
    obj->arr[obj->tail] = val;
    int temp = obj->tail;
    (obj->tail)++;
    int mid;
    while (temp > 0 && obj->arr[temp] > obj->arr[(temp - 1) >> 1]) {
        mid = obj->arr[temp];
        obj->arr[temp] = obj->arr[(temp - 1) >> 1];
        obj->arr[(temp - 1) >> 1] = mid;
        temp = (temp - 1) >> 1;
    }
}
void deleteMaxHeap(struct MaxHeap* obj) {
    if (isEmpty(obj)) return;
    int left, right, par = 0;
    while (1) {
        left = 2 * par + 1;
        right = 2* par + 2;
        if (right < obj->tail) {
            if (obj->arr[left] < obj->arr[right]) {
                obj->arr[par] = obj->arr[right];
                par = right;
            } else {
                obj->arr[par] = obj->arr[left];
                par = left;
            }
        } else if (left < obj->tail) {
            obj->arr[par] = obj->arr[left];
            break;
        } else if (left >= obj->tail) {
            obj->arr[par] = obj->arr[obj->tail - 1];
            int temp = par, mid;
            while (temp > 0 && obj->arr[temp] > obj->arr[(temp - 1) >> 1]) {
                mid = obj->arr[temp];
                obj->arr[temp] = obj->arr[(temp - 1) >> 1];
                obj->arr[(temp - 1) >> 1] = mid;
                temp = (temp - 1) >> 1;
            }
            break;
        }
    }
    (obj->tail)--;
}
void freeMaxHeap(struct MaxHeap* obj) {
    free(obj->arr);
    free(obj);
}
int lastStoneWeight(int* stones, int stonesSize){
    struct MaxHeap* obj = createMaxHeap(stonesSize);
    for (int i = 0; i < stonesSize; i++) {
        insertMaxHeap(obj, stones[i]);
    }
    int max1, max2, temp;
    while (obj->tail > 1) {
        max1 = obj->arr[0];
        deleteMaxHeap(obj);
        max2 = obj->arr[0];
        deleteMaxHeap(obj);
        temp = max1 - max2;
        if (temp != 0) insertMaxHeap(obj, temp);
    }
    int res = 0;
    if (isEmpty(obj) == false) res = obj->arr[0];
    freeMaxHeap(obj);
    return res;
}

int main() {
    int stones[] = {2,7,4,1,8,1};
    int nums = sizeof(stones) / sizeof(int);
    int res = lastStoneWeight(stones, nums);
    printf("%d\n", res);
    return 0;
}
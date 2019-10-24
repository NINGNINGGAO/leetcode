/*
 * @Author: AGOGIN
 * @Date: 2019-10-24 21:40:21
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-24 22:11:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAXSIZE 10240
typedef struct {
    int* Data;
    int* Min;
    int topData;
    int topMin;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));
    obj->Data = malloc(sizeof(int) * MAXSIZE);
    obj->Min = malloc(sizeof(int) * MAXSIZE);
    obj->topData = -1;
    obj->topMin = -1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->topMin == -1 || obj->Min[obj->topMin] >= x) {
        obj->topMin++;
        obj->Min[obj->topMin] = x;
    }
    obj->topData++;
    obj->Data[obj->topData] = x;
}

void minStackPop(MinStack* obj) {
    if (obj->topData >= 0) {
        if (obj->Data[obj->topData] == minStackGetMin(obj)) {
            obj->topMin--;
        }
        obj->topData--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->topData >= 0) return obj->Data[obj->topData];
    else return NULL;
}

int minStackGetMin(MinStack* obj) {
    if (obj->topMin >= 0) return obj->Min[obj->topMin];
    else return NULL;
}

void minStackFree(MinStack* obj) {
    free(obj->Data);
    free(obj->Min);
    free(obj);
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
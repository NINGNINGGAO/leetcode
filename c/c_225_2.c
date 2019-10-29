/*
 * @Author: AGOGIN
 * @Date: 2019-10-29 16:28:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-29 17:41:19
 */
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 2048

typedef struct {
    int* q1;
    int* q2;
    int q1Num, q2Num;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));
    obj->q1 = malloc(sizeof(int) * MAXSIZE);
    obj->q2 = malloc(sizeof(int) * MAXSIZE);
    obj->q1Num = 0;
    obj->q2Num = 0;
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->q2[obj->q2Num++] = x;
    for (int i = 0; i < obj->q1Num; i++) {
        obj->q2[obj->q2Num++] = obj->q1[i];
    }
    int* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    obj->q1Num = obj->q2Num;
    obj->q2Num = 0;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int res = obj->q1[0];
    for (int i = 1; i < obj->q1Num; i++) {
        obj->q2[obj->q2Num++] = obj->q1[i];
    }
    int* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    obj->q1Num = obj->q2Num;
    obj->q2Num = 0;
    return res;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->q1[0];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->q1Num == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
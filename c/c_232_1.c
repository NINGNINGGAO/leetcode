/*
 * @Author: AGOGIN
 * @Date: 2019-10-29 20:12:42
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-29 20:30:42
 */
#include <stdbool.h>
#define MAXSIZE 2048
typedef struct {
    int* s;
    int num;
} MyStack;

typedef struct {
    MyStack* s1;
    MyStack* s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    obj->s1 = malloc(sizeof(MyStack));
    obj->s2 = malloc(sizeof(MyStack));
    obj->s1->s = malloc(sizeof(int) * MAXSIZE);
    obj->s2->s = malloc(sizeof(int) * MAXSIZE);
    obj->s1->num = 0;
    obj->s2->num = 0;
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->s1->s[obj->s1->num++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (obj->s2->num == 0) {
        while (obj->s1->num != 0) {
            obj->s2->s[obj->s2->num++] = obj->s1->s[--obj->s1->num];
        }
    }
    int res = obj->s2->s[--obj->s2->num];
    return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj->s2->num == 0) {
        while (obj->s1->num != 0) {
            obj->s2->s[obj->s2->num++] = obj->s1->s[--obj->s1->num];
        }
    }
    int res = obj->s2->s[obj->s2->num - 1];
    return res;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->s1->num == 0 && obj->s2->num == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1->s);
    free(obj->s2->s);
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 22:22:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 10:06:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define maxSize 10000
struct Node {
    int val;
    struct Node* next;
};
typedef struct {
    struct Node* arr;
} MyHashSet;

bool myHashSetContains(MyHashSet* obj, int key);
/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = malloc(sizeof(MyHashSet));
    obj->arr = malloc(sizeof(struct Node) * maxSize);
    memset(obj->arr, 0, sizeof(struct Node) * maxSize);
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (myHashSetContains(obj, key) == false) {
        struct Node* temp = malloc(sizeof(struct Node));
        temp->val = key;
        temp->next = NULL;
        struct Node* mid;
        mid = obj->arr[key % maxSize].next;
        temp->next = mid;
        obj->arr[key % maxSize].next = temp;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    struct Node *mid, *temp;
    temp = &(obj->arr[key % maxSize]);
    while (temp->next != NULL) {
        if (temp->next->val != key) temp = temp->next;
        else {
            mid = temp->next->next;
            free(temp->next);
            temp->next = mid;
        }
    }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    struct Node *mid, *temp;
    temp = &(obj->arr[key % maxSize]);
    while (temp->next != NULL) {
        if (temp->next->val != key) temp = temp->next;
        else return true;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    struct Node *temp, *mid;
    for (int i = 0; i < maxSize; i++) {
        temp = obj->arr[i].next;
        while (temp != NULL) {
            mid = temp;
            temp = temp->next;
            free(mid);
        }
    }
    free(obj->arr);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/

int main() {
    MyHashSet* obj = myHashSetCreate();
    myHashSetAdd(obj, 1);
    myHashSetAdd(obj, 2);
    bool res1 = myHashSetContains(obj, 1);
    bool res2 = myHashSetContains(obj, 3);
    myHashSetAdd(obj, 2);
    bool res3 = myHashSetContains(obj, 2);
    myHashSetRemove(obj, 2);
    bool res4 = myHashSetContains(obj, 2);
    myHashSetFree(obj);
    return 0;
}
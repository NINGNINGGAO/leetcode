/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 22:53:15
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 10:09:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define maxSize 10000
struct Node {
    int key;
    int value;
    struct Node* next;
};
typedef struct {
    struct Node* arr;
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() {
    MyHashMap* obj = malloc(sizeof(MyHashMap));
    obj->arr = malloc(sizeof(struct Node) * maxSize);
    memset(obj->arr, 0, sizeof(struct Node) * maxSize);
    return obj;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->key = key;
    temp->value = value;
    temp->next = NULL;
    struct Node* mid;
    mid = obj->arr[key % maxSize].next;
    temp->next = mid;
    obj->arr[key % maxSize].next = temp;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
    struct Node *mid, *temp;
    temp = &(obj->arr[key % maxSize]);
    while (temp->next != NULL) {
        if (temp->next->key != key) temp = temp->next;
        else return temp->next->value;
    }
    return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    struct Node *mid, *temp;
    temp = &(obj->arr[key % maxSize]);
    while (temp->next != NULL) {
        if (temp->next->key != key) temp = temp->next;
        else {
            mid = temp->next->next;
            free(temp->next);
            temp->next = mid;
        }
    }
}

void myHashMapFree(MyHashMap* obj) {
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
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 16:59:09
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 17:22:48
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node {
    int val;
    struct Node* next;
};
typedef struct {
    int size;
    struct Node* head;
    struct Node* last;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = malloc(sizeof(RecentCounter));
    memset(obj, 0, sizeof(RecentCounter));
    obj->head = malloc(sizeof(struct Node));
    memset(obj->head, 0, sizeof(struct Node));
    obj->last = obj->head;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    struct Node *temp, *mid;
    temp = malloc(sizeof(struct Node));
    memset(temp, 0, sizeof(struct Node));
    temp->val = t;
    obj->last->next = temp;
    obj->last = obj->last->next;
    (obj->size)++;
    while (obj->head->next->val + 3000 < t) {
        mid = obj->head->next;
        obj->head->next = mid->next;
        (obj->size)--;
        free(mid);
    }
    return obj->size;
}

void recentCounterFree(RecentCounter* obj) {
    struct Node *mid;
    while (obj->head->next != NULL) {
        mid = obj->head->next;
        obj->head->next = mid->next;
        free(mid);
    }
    free(obj->head);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/

int main() {

    return 0;
}
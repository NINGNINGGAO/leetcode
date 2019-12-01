/*
 * @Author: AGOGIN
 * @Date: 2019-12-01 18:12:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-01 18:21:37
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL || k == 0) return head;
    struct ListNode *temp, *tmp, *res;
    temp = head;
    int listSize = 1;
    while (temp->next != NULL) {
        listSize++;
        temp = temp->next;
    }
    k %= listSize;
    if (k == 0) return head;
    tmp = head;
    for (int i = 0; i < listSize - k; i++) {
        tmp = tmp->next;
    }
    res = tmp->next;
    tmp->next = NULL;
    temp->next = head;
    return res;
}

int main() {

    return 0;
}
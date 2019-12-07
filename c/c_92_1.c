/*
 * @Author: AGOGIN
 * @Date: 2019-12-07 14:15:53
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-07 14:27:14
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
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode *res, *temp1, *temp2, *mid1, *mid2;
    res = malloc(sizeof(struct ListNode));
    res->next = head;
    temp1 = res, temp2 = res;
    for (int i = 1; i < m; i++) {
        temp1 = temp1->next;
    }
    for (int i = 0; i < n; i++) {
        temp2 = temp2->next;
    }
    mid1 = temp1->next;
    mid2 = temp2->next;
    temp2->next = NULL;
    temp1->next = reverseList(mid1);
    mid1->next = mid2;
    mid1 = res;
    res = res->next;
    free(mid1);
    return res;
}

int main() {

    return 0;
}
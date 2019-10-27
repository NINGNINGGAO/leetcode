/*
 * @Author: AGOGIN
 * @Date: 2019-10-27 16:01:18
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-27 17:04:33
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *temp, *mid, *tmp;
    temp = head;
    while (temp != NULL && temp->val == val) {
        head = temp->next;
        free(temp);
        temp = head;
    }
    if (temp == NULL) return head;
    mid = temp->next;
    while (mid != NULL) {
        if (mid->val == val) {
            tmp = mid->next;
            temp->next = tmp;
            free(mid);
            mid = tmp;
        } else {
            temp = mid;
            mid = temp->next;
        }
    }
    return head;
}

int main() {

    return 0;
}
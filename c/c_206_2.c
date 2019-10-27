/*
 * @Author: AGOGIN
 * @Date: 2019-10-27 22:21:23
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-27 22:23:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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

int main() {

    return 0;
}
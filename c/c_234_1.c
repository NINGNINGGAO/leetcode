/*
 * @Author: AGOGIN
 * @Date: 2019-10-30 10:03:59
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-30 10:56:47
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
struct ListNode* reverseList(struct ListNode* head, struct ListNode* flag) {
    if (head == flag) return head;
    struct ListNode *res = reverseList(head->next, flag);
    head->next->next = head;
    head->next = NULL;
    return res;
}

bool isPalindrome(struct ListNode* head){
    if (head == NULL || head->next == NULL) return true;
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *p1, *p2;
    p1 = slow->next;
    struct ListNode* temp = reverseList(head, slow);
    if (fast->next != NULL) p2 = temp;
    else p2 = temp->next;
    while (p1 != NULL) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main() {

    return 0;
}
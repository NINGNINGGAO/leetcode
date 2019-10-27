/*
 * @Author: AGOGIN
 * @Date: 2019-10-27 22:14:36
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-27 22:21:12
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
    struct ListNode *prev = NULL, *curr = head, *temp;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main() {

    return 0;
}
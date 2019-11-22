/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 15:07:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 15:10:35
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
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *fast = head, *slow = head;
    while (1) {
        if (fast->next != NULL) fast = fast->next;
        else break;
        slow = slow->next;
        if (fast->next != NULL) fast = fast->next;
        else break;
    }
    return slow;
}

int main() {

    return 0;
}
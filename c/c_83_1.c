/*
 * @Author: AGOGIN
 * @Date: 2019-10-17 11:13:01
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-17 20:48:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *temp, *mid, *tmp1, *tmp2;
    temp = head;
    if (head == NULL) return NULL;
    mid = temp->next;
    while (temp->next != NULL) {
        if (mid != NULL && mid->val == temp->val) {
            mid = mid->next;
        } else {
            tmp1 = temp->next;
            while (tmp1 != mid) {
                tmp2 = tmp1->next;
                free(tmp1);
                tmp1 = tmp2;
            }
            temp->next = mid;
            if (mid != NULL) {
                temp = mid;
                mid = temp->next;
            } else {
                break;
            }
        }
    }
    return head;
}

int main() {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *temp, *mid;
    char tmp;
    do {
        temp = malloc(sizeof(struct ListNode));
        scanf("%d%c", &(temp->val), &tmp);
        mid = head->next;
        head->next = temp;
        temp->next = mid;
    } while (tmp != '\n');
    struct ListNode *ret = deleteDuplicates(head->next);
    return 0;
}
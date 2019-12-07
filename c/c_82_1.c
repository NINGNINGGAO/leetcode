/*
 * @Author: AGOGIN
 * @Date: 2019-12-06 18:48:19
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-06 19:41:15
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
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *res, *temp, *cur, *mid;
    res = malloc(sizeof(struct ListNode));
    res->next = head;
    cur = res;
    while (cur != NULL) {
        temp = cur;
        cur = cur->next;
        while (cur != NULL && cur->next != NULL && cur->val == cur->next->val) {
            int t = cur->val;
            while (cur != NULL && cur->val == t) {
                mid = cur;
                cur = cur->next;
                free(mid);
            }
            temp->next = cur;
        }
    }
    mid = res;
    res = res->next;
    free(mid);
    return res;
}

int main() {

    return 0;
}
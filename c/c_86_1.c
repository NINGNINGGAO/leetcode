/*
 * @Author: AGOGIN
 * @Date: 2019-12-06 19:42:49
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-06 19:52:22
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
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *res1, *res2, *p, *q, *temp;
    res1 = malloc(sizeof(struct ListNode));
    res2 = malloc(sizeof(struct ListNode));
    p = res1;
    q = res2;
    while (head != NULL) {
        temp = head;
        head = head->next;
        if (temp->val < x) {
            p->next = temp;
            p = p->next;
        } else {
            q->next = temp;
            q = q->next;
        }
    }
    q->next = NULL;
    temp = res2;
    p->next = temp->next;
    free(temp);
    temp = res1;
    res1 = res1->next;
    free(temp);
    return res1;
}

int main() {

    return 0;
}
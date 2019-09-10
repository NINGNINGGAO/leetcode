/*
 * @Author: AGOGIN
 * @Date: 2019-09-06 22:02:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-06 22:12:00
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head, struct ListNode **meetNode);

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* meetNode;
    bool flag = hasCycle(head, &meetNode);
    if (flag == 1) {
        int num = 1;
        struct ListNode* temp = meetNode->next;
        while (temp != meetNode) {
            temp = temp->next;
            num++;
        }
        struct ListNode *pSlow = head, *pFast = head;
        for (int i = 0; i < num; i++) {
            pFast = pFast->next;
        }
        while (pFast != pSlow) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        meetNode = pFast;
    }
    return meetNode;
}

bool hasCycle(struct ListNode *head, struct ListNode **meetNode) {
    if (head == NULL) {
        return 0;
    }
    struct ListNode *pSlow, *pFast;
    pSlow = head;
    pFast = head;
    do {
        pSlow = pSlow->next;
        if (pSlow == NULL) return 0;
        pFast = pFast->next;
        if (pFast == NULL) return 0;
        pFast = pFast->next;
        if (pFast == NULL) return 0;
        if (pFast == pSlow) {
            *meetNode = pSlow;
            return 1;
        }
    } while (1);
}

int main() {
    struct ListNode *phead = malloc(sizeof(struct ListNode));
    struct ListNode *temp, *mid;
    int tmp;
    do {
        temp = phead->next;
        mid = malloc(sizeof(struct ListNode));
        scanf("%d%c", &(mid->val), &tmp);
        phead->next = mid;
        mid->next = temp;
    } while (tmp != '\n');
    temp = phead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = phead->next->next;
    struct ListNode *p = detectCycle(phead->next);
    printf("%d\n", p->val);
    return 0;
}
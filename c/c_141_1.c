/*
 * @Author: AGOGIN
 * @Date: 2019-09-06 21:49:42
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-06 22:04:21
 */
#include <stdio.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return 0;
    }
    struct ListNode *pSlow, *pFast;
    pSlow = head;
    pFast = head;
    do {
        pSlow = pSlow->next;
        if (pSlow == NULL) {
            return 0;
        }
        pFast = pFast->next;
        if (pFast == NULL) {
            return 0;
        }
        pFast = pFast->next;
        if (pFast == NULL) {
            return 0;
        }
        if (pFast == pSlow) {
            return 1;
        }
    } while (1);
}
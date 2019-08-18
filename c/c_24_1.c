/*
 * @Author: AGOGIN 
 * @Date: 2019-08-18 20:26:30 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-08-18 20:26:30 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p = malloc(sizeof(struct ListNode));
    struct ListNode *q;
    p->val = NULL;
    p->next = head;
    q = p;
    struct ListNode *temp = malloc(sizeof(struct ListNode));
    temp->next = NULL;
    while (p->next != NULL && p->next->next != NULL) {
        temp->next = p->next->next->next;
        p->next->next->next = p->next;
        p->next = p->next->next;
        p->next->next->next = temp->next;
        p = p->next->next;
    }
    return q->next;
}
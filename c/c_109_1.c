/*
 * @Author: AGOGIN 
 * @Date: 2020-03-17 21:27:17 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-17 22:52:25
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedListToBST(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHead->next = head;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct ListNode *fast = head, *slow = head, *prev = pHead, *temp;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        prev = prev->next;
        slow = slow->next;
    }
    root->val = slow->val;
    temp = slow->next;
    prev->next = NULL;
    free(slow);
    struct ListNode* qHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    qHead->next = temp;
    root->left = sortedListToBST(pHead->next);
    free(pHead);
    root->right = sortedListToBST(qHead->next);
    free(qHead);
    return root;
}

int main() {
    
    return 0;
}
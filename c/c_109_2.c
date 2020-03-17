/*
 * @Author: AGOGIN 
 * @Date: 2020-03-17 22:51:32 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-17 23:06:28
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
//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int begin, int end) {
    if (begin > end) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = nums[(end + 1 - begin) / 2 + begin];
    root->left = sortedArrayToBST(nums, begin, (end + 1 - begin) / 2 + begin - 1);
    root->right = sortedArrayToBST(nums, (end + 1 - begin) / 2 + begin + 1, end);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode* temp;
    int* nums = malloc(sizeof(int) * 1024);
    int numsSize = 0;
    while (head != NULL) {
        nums[numsSize++] = head->val;
        temp = head;
        head = head->next;
        free(temp);
    }
    struct TreeNode* root = sortedArrayToBST(nums, 0, numsSize - 1);
    free(nums);
    return root;
}

int main() {
    
    return 0;
}
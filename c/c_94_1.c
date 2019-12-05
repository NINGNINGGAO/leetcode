/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 11:17:37
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-05 15:15:08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void morris(struct TreeNode* root, int* res, int* returnSize) {
    if (root == NULL) return;
    struct TreeNode *cur, *mostRight;
    cur = root;
    while (cur != NULL) {
        mostRight = cur->left;
        if (mostRight != NULL) {
            while (mostRight->right != NULL && mostRight->right != cur) mostRight = mostRight->right;
            if (mostRight->right == NULL) {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else {
                mostRight->right = NULL;
            }
        }
        res[(*returnSize)++] = cur->val;
        cur = cur->right;
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int* res = malloc(sizeof(int) * 2048);
    morris(root, res, returnSize);
    return res;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-10-30 11:14:28
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-30 15:59:14
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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int min = p->val, max = q->val;
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }
    while (root != NULL) {
        if (root->val < min) {
            root = root->right;
        } else if (root->val > max) {
            root = root->left;
        } else return root;
    }
    return NULL;
}

int main() {

    return 0;
}
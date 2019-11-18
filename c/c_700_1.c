/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 17:35:08
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 17:37:34
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
struct TreeNode* searchBST(struct TreeNode* root, int val){
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    if (root->val < val) return searchBST(root->right, val);
    return searchBST(root->left, val);
}

int main() {

    return 0;
}
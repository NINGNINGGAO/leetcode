/*
 * @Author: AGOGIN
 * @Date: 2019-10-28 15:56:37
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-28 16:18:33
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return NULL;
    struct TreeNode *R = invertTree(root->right);
    struct TreeNode *L = invertTree(root->left);
    root->left = R;
    root->right = L;
    return root;
}

int main() {

    return 0;
}
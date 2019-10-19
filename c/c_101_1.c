/*
 * @Author: AGOGIN
 * @Date: 2019-10-19 11:39:52
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-19 13:13:18
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


bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

int isMirror(struct TreeNode* L, struct TreeNode* R) {
    if (L == NULL && R == NULL) return true;
    if (L == NULL || R == NULL) return false;
    return (L->val == R->val && isMirror(L->left, R->right) && isMirror(L->right, R->left));
}

int main() {

    return 0;
}
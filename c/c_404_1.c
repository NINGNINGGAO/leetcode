/*
 * @Author: AGOGIN
 * @Date: 2019-11-05 09:29:51
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-05 09:37:35
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
int sumOfLeftLeaves(struct TreeNode* root){
    int res = 0;
    if (root == NULL) return res;
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        res += root->left->val;
    }
    res += sumOfLeftLeaves(root->left);
    res += sumOfLeftLeaves(root->right);
    return res;
}

int main() {

    return 0;
}
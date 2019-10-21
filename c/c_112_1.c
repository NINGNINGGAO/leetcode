/*
 * @Author: AGOGIN
 * @Date: 2019-10-21 13:07:12
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-21 13:30:29
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

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) return false;
    if (!root->left && !root->right && sum == root->val) return true;
    if (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val)) return true;
    else return false;
}

int main() {

    return 0;
}
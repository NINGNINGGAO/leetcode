/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 18:04:49
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 18:07:38
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
bool dfs(struct TreeNode* root, int num) {
    if (root == NULL) return true;
    if (root->val != num) return false;
    else return dfs(root->left, num) && dfs(root->right, num);
}
bool isUnivalTree(struct TreeNode* root){
    return dfs(root, root->val);
}

int main() {

    return 0;
}
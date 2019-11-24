/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 15:56:23
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 16:06:30
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
void dfs(struct TreeNode* root, int num, int* res) {
    if (root->left == NULL && root->right == NULL) {
        *res += ((num << 1) + root->val);
        return;
    }
    num = (num << 1) + root->val;
    if (root->left != NULL) dfs(root->left, num, res);
    if (root->right != NULL) dfs(root->right, num, res);
}
int sumRootToLeaf(struct TreeNode* root){
    int num = 0;
    int res = 0;
    dfs(root, num, &res);
    return res;
}

int main() {

    return 0;
}
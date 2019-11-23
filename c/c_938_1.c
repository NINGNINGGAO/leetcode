/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 13:50:48
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 13:59:42
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
void dfs(struct TreeNode* root, int* res, int L, int R) {
    if (root == NULL) return;
    if (root->val > L) dfs(root->left, res, L, R);
    if (root->val >= L && root->val <= R) *res += root->val;
    if (root->val < R) dfs(root->right, res, L, R);
}
int rangeSumBST(struct TreeNode* root, int L, int R){
    int res = 0;
    dfs(root, &res, L, R);
    return res;
}

int main() {

    return 0;
}
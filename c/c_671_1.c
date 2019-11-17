/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 18:13:36
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 18:30:03
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
int dfs(struct TreeNode* root, int n) {
    if (root == NULL) return -1;
    if (root->val > n) return root->val;
    else {
        int L = dfs(root->left, n);
        int R = dfs(root->right, n);
        if (L > n && R > n) return L < R ? L : R;
        return L > R ? L : R;
    }
    return -1;
}
int findSecondMinimumValue(struct TreeNode* root){
    int n = root->val;
    return dfs(root, n);
}

int main() {

    return 0;
}
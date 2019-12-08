/*
 * @Author: AGOGIN
 * @Date: 2019-12-07 22:32:30
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-08 13:51:53
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
bool isValidBackTrack(struct TreeNode* root, long long lower, long long upper) {
    if (root == NULL) return true;
    if (root->left != NULL && root->left->val >= root->val) return false;
    if (root->right != NULL && root->right->val <= root->val) return false;
    if (root->val >= upper || root->val <= lower) return false;
    return isValidBackTrack(root->left, lower, root->val) && isValidBackTrack(root->right, root->val, upper);
}
bool isValidBST(struct TreeNode* root){
    long long lower = (long long)INT_MIN - 1024, upper = (long long)INT_MAX + 1024;
    return isValidBackTrack(root, lower, upper);
}

int main() {
    struct TreeNode a = {1, NULL, NULL};
    struct TreeNode b = {3, NULL, NULL};
    struct TreeNode c = {2, &a, &b};
    bool res = isValidBST(&c);
    return 0;
}
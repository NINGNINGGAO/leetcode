/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 17:57:32
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 18:12:09
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
struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
    if (root == NULL) return NULL;
    struct TreeNode* res;
    if (root->val > R) {
        res = trimBST(root->left, L, R);
        return res;
    }
    if (root->val< L) {
        res = trimBST(root->right, L, R);
        return res;
    }
    res = root;
    res->left = trimBST(root->left, L, R);
    res->right = trimBST(root->right, L, R);
    return res;
}

int main() {
    struct TreeNode a = {0,NULL, NULL};
    struct TreeNode b = {2,NULL, NULL};
    struct TreeNode c = {1,&a, &b};
    struct TreeNode* res = trimBST(&c, 1, 2);
    return 0;
}
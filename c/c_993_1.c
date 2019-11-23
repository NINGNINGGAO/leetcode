/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 21:21:04
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 21:56:53
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
struct Node {
    int val;
    int par;
};
void dfs(struct TreeNode* root, int x, int y, struct Node* res,int depth) {
    if (root->left != NULL) {
        if (root->left->val == x) {
            res[0].val = depth;
            res[0].par = root->val;
        } else if (root->left->val == y) {
            res[1].val = depth;
            res[1].par = root->val;
        }
    dfs(root->left, x, y, res, depth + 1);
    }
    if (root->right != NULL) {
        if (root->right->val == x) {
            res[0].val = depth;
            res[0].par = root->val;
        } else if (root->right->val == y) {
            res[1].val = depth;
            res[1].par = root->val;
        }
    dfs(root->right, x, y, res, depth + 1);
    }
}
bool isCousins(struct TreeNode* root, int x, int y){
    struct Node* res = malloc(sizeof(struct Node) * 2);
    memset(res, 0, sizeof(struct Node) * 2);
    int depth = 1;
    dfs(root, x, y, res, depth);
    if (res[0].val != res[1].val) return false;
    else if (res[0].par == res[1].par) return false;
    else return true;
}

int main() {

    return 0;
}
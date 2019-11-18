/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 11:37:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 17:13:22
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
#define Max(a, b) ((a) > (b) ? (a) : (b))
int arrowLength(struct TreeNode* root, int* res) {
    if (root == NULL) return 0;
    int left = arrowLength(root->left, res);
    int right = arrowLength(root->right, res);
    int arrowLeft = 0, arrowRight = 0;
    if (root->left != NULL && root->val == root->left->val) arrowLeft += left + 1;
    if (root->right != NULL && root->val == root->right->val) arrowRight += right + 1;
    *res = Max((*res), arrowLeft + arrowRight);
    return Max(arrowLeft, arrowRight);
}
int longestUnivaluePath(struct TreeNode* root){
    int res = 0;
    int temp = arrowLength(root, &res);
    return res;
}

int main() {

    return 0;
}
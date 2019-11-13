/*
 * @Author: AGOGIN
 * @Date: 2019-11-13 13:03:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-13 13:06:27
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int deep(struct TreeNode* root, int* res) {
    if (root == NULL) return -1;
    int left = deep(root->left, res) + 1;
    int right = deep(root->right, res) + 1;
    if (*res < left + right) *res = left + right;
    return Max(left, right);
}
int diameterOfBinaryTree(struct TreeNode* root){
    int res = 0;
    int depth = deep(root, &res);
    return res;
}

int main() {

    return 0;
}
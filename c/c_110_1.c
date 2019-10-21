/*
 * @Author: AGOGIN
 * @Date: 2019-10-21 12:35:54
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-21 12:52:16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define abs(a, b) ((a) - (b) < 0 ? (-(a) + (b)) : ((a) - (b)))
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root){
    return (deepNum(root) != -1);
}

int deepNum(struct TreeNode* root) {
    if (root == NULL) return 0;
    int L, R;
    L = deepNum(root->left);
    if (L == -1) return -1;
    R = deepNum(root->right);
    if (R == -1) return -1;
    if (abs(L, R) > 1) return -1;
    return (L > R ? L : R) + 1;
}

int main() {

    return 0;
}
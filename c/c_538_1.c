/*
 * @Author: AGOGIN
 * @Date: 2019-11-13 10:16:42
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-13 10:25:54
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
void reverseInOrder(struct TreeNode* root, int* accumVal) {
    if (root == NULL) return;
    reverseInOrder(root->right, accumVal);
    *accumVal += root->val;
    root->val = *accumVal;
    reverseInOrder(root->left, accumVal);
}
struct TreeNode* convertBST(struct TreeNode* root){
    if (root == NULL) return NULL;
    int accumVal = 0;
    reverseInOrder(root, &accumVal);
    return root;
}

int main() {

    return 0;
}
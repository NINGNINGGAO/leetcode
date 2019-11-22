/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 16:57:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 20:48:55
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
void inOrder(struct TreeNode* root, struct TreeNode** newRoot) {
    if (root == NULL) return;
    inOrder(root->left, newRoot);
    root->left = NULL;
    (*newRoot)->right = root;
    (*newRoot) = root;
    inOrder(root->right, newRoot);
}
struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode* newRoot, *mid;
    newRoot = malloc(sizeof(struct TreeNode));
    mid = newRoot;
    inOrder(root, &newRoot);
    newRoot = mid->right;
    free(mid);
    return newRoot;
}

int main() {
    struct TreeNode b = {3,NULL, NULL};
    struct TreeNode c = {2,NULL, NULL};
    struct TreeNode a = {1,&c, &b};
    struct TreeNode* res = increasingBST(&a);
    return 0;
}
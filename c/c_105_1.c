/*
 * @Author: AGOGIN 
 * @Date: 2020-03-16 19:55:05 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-17 20:10:46
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

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorderSize <= 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int index = 0;
    while (index < inorderSize && inorder[index] != preorder[0]) index++;
    root->left = buildTree(preorder + 1, index, inorder, index);
    root->right = buildTree(preorder + 1 + index, preorderSize - 1 - index, \
    inorder + 1 + index, inorderSize - 1 - index);
    return root;
}

int main() {
    
    return 0;
}
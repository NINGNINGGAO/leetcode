/*
 * @Author: AGOGIN 
 * @Date: 2020-03-17 20:12:32 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-17 20:40:09
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

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (inorderSize <= 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    int index = 0;
    while (index < inorderSize && inorder[index] \
    != postorder[postorderSize - 1]) index++;
    root->left = buildTree(inorder, index, \
    postorder, index);
    root->right = buildTree(inorder + index + 1, inorderSize - index - 1, \
    postorder + index, postorderSize - index - 1);
    return root;
}

int main() {
    
    return 0;
}
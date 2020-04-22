/*
 * @Author: AGOGIN 
 * @Date: 2020-04-22 22:09:06 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-22 22:18:49
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void DFS(struct TreeNode* root, int** ret, int* returnSize, int layer) {
    if (root == NULL) return;
    if (layer >= *returnSize) (*ret)[(*returnSize)++] = root->val;
    DFS(root->right, ret, returnSize, layer + 1);
    DFS(root->left, ret, returnSize, layer + 1);
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int* ret = malloc(sizeof(int) * 1000);
    memset(ret, 0, sizeof(int) * 1000);
    DFS(root, &ret, returnSize, 0);
    return ret;
}

int main() {
    
    return 0;
}
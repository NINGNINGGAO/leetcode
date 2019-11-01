/*
 * @Author: AGOGIN
 * @Date: 2019-10-31 15:29:44
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-01 17:19:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define MAXSIZE 128
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int path[MAXSIZE];
    int depth = 0;
    *returnSize = 0;
    if (root == NULL) return NULL;
    char** res = malloc(sizeof(int*) * MAXSIZE);
    dfs(root, returnSize, res, path, depth);
    return res;
}
void dfs(struct TreeNode* root, int* returnSize, char** res, int* path, int depth) {
    int i = 0;
    path[depth++] = root->val;
    if (root->left == NULL && root->right == NULL) {
        res[*returnSize] = malloc(sizeof(int) * MAXSIZE);
        res[*returnSize][0] = 0;
        for (i = 0; i < depth - 1; i++) {
            sprintf(res[*returnSize], "%s%d->", res[*returnSize], path[i]);
        }
        sprintf(res[*returnSize], "%s%d", res[*returnSize], path[i]);
        (*returnSize)++;
    }
    if (root->left != NULL) dfs(root->left, returnSize, res, path, depth);
    if (root->right != NULL) dfs(root->right, returnSize, res, path, depth);
}

int main() {
    struct TreeNode temp4 = {5, NULL, NULL};
    struct TreeNode temp3 = {2, NULL, &temp4};
    struct TreeNode temp2 = {3, NULL, NULL};
    struct TreeNode root = {1, &temp3, &temp2};
    int returnSize;
    char** res = binaryTreePaths(&root, &returnSize);
    return 0;
}
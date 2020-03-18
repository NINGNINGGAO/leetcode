/*
 * @Author: AGOGIN 
 * @Date: 2020-03-18 11:09:39 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-18 15:13:02
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define maxNum 1024
bool dfs(struct TreeNode* root, int sum, int** ret, \
int* returnSize, int** returnColumnSizes, int level) {
    if (root == NULL) return false;
    ret[*returnSize][level] = root->val;
    if (!root->left && !root->right && sum == root->val) {
        (*returnColumnSizes)[*returnSize] = level + 1;
        (*returnSize)++;
        ret[*returnSize] = malloc(sizeof(int) * maxNum);
        memcpy(ret[*returnSize], ret[*returnSize - 1], sizeof(int) * level);
        return true;
    }
    bool temp1 = dfs(root->left, sum - root->val, ret, returnSize, returnColumnSizes, level + 1);
    bool temp2 = dfs(root->right, sum - root->val, ret, returnSize, returnColumnSizes, level + 1);
    if (temp1 || temp2) return true;
    else return false;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) return NULL;
    *returnColumnSizes = malloc(sizeof(int) * maxNum);
    memset(*returnColumnSizes, 0, sizeof(int) * maxNum);
    int** ret = (int**)malloc(sizeof(int*) * maxNum);
    ret[*returnSize] = (int*)malloc(sizeof(int) * maxNum);
    dfs(root, sum, ret, returnSize, returnColumnSizes, 0);
    if (returnSize == 0) {
        free(ret[*returnSize]);
        free(ret);
        free(returnColumnSizes);
        return NULL;
    } else return ret;
}

int main() {
    struct TreeNode a10 = {1, NULL, NULL};
    struct TreeNode a9 = {5, NULL, NULL};
    struct TreeNode a8 = {2, NULL, NULL};
    struct TreeNode a7 = {7, NULL, NULL};
    struct TreeNode a6 = {4, &a9, &a10};
    struct TreeNode a5 = {13, NULL, NULL};
    struct TreeNode a4 = {11, &a7, &a8};
    struct TreeNode a3 = {8, &a5, &a6};
    struct TreeNode a2 = {4, &a4, NULL};
    struct TreeNode a1 = {5, &a2, &a3};
    int sum = 22;
    int returnSize = 0;
    int* returnColumnSizes;
    int** ret = pathSum(&a1, sum, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}
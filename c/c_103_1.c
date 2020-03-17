/*
 * @Author: AGOGIN 
 * @Date: 2020-03-16 18:07:31 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-16 18:19:45
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
void dfs(struct TreeNode* root, int* returnSize, int**returnColumnSizes, \
int** ret, int level) {
    if (root == NULL) return;
    if (*returnSize <= level) {
        ret[*returnSize] = (int*)malloc(sizeof(int) * 2048);
        // printf("%d\n", ((*returnColumnSizes)[(*returnSize) > 0 ? ((*returnSize) - 1) :  0] * 2 + 1));
        (*returnSize)++;
    }
    ret[level][((*returnColumnSizes)[level])++] = root->val;
    dfs(root->left, returnSize, returnColumnSizes, ret, level + 1);
    dfs(root->right, returnSize, returnColumnSizes, ret, level + 1);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** ret = malloc(sizeof(int*) * maxNum);
    (*returnSize) = 0;
    if (root == NULL) return ret;
    *returnColumnSizes = malloc(sizeof(int) * maxNum);
    memset(*returnColumnSizes, 0, sizeof(int) * maxNum);
    int level = 0;
    dfs(root, returnSize, returnColumnSizes, ret, level);
    return ret;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** ret = levelOrder(root, returnSize, returnColumnSizes);
    for (int i = 1; i < (*returnSize); i = i + 2) {
        for (int j = 0; j < (*returnColumnSizes)[i] / 2; j++) {
            int temp = ret[i][j];
            ret[i][j] = ret[i][(*returnColumnSizes)[i] - 1 - j];
            ret[i][(*returnColumnSizes)[i] - 1 - j] = temp;
        }
    }
    return ret;
}

int main() {
    
    return 0;
}
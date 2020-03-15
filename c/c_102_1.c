/*
 * @Author: AGOGIN 
 * @Date: 2020-03-14 18:53:36 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-15 10:45:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#define maxNum 1024
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


int main() {
    struct TreeNode a10 = {8, NULL, NULL};
    struct TreeNode a9 = {6, NULL, NULL};
    struct TreeNode a8 = {1, NULL, NULL};
    struct TreeNode a7 = {5, NULL, NULL};
    struct TreeNode a6 = {-1, NULL, &a10};

    struct TreeNode a5 = {3, NULL, &a9};
    struct TreeNode a4 = {1, &a7, &a8};
    struct TreeNode a3 = {4, &a5, &a6};
    struct TreeNode a2 = {2, &a4, NULL};
    struct TreeNode a1 = {0, &a2, &a3};
    int returnSize = 0;
    int* returnColumnSizes;
    int** ret = levelOrder(&a1, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}

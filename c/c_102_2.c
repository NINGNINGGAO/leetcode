/*
 * @Author: AGOGIN 
 * @Date: 2020-03-15 10:05:10 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-16 01:23:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
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

void bfs(int* returnSize, int** axlMat, struct TreeNode*** axlret) {
    if ((*axlMat)[*returnSize] == 0) return;
    axlret[*returnSize + 1] = malloc(sizeof(struct TreeNode*) * 2 * (*axlMat)[*returnSize]);
    for (int i = 0; i < (*axlMat)[*returnSize]; i++) {
        if (axlret[*returnSize][i]->left != NULL) {
            axlret[*returnSize + 1][((*axlMat)[*returnSize + 1])++] = \
            axlret[*returnSize][i]->left;
        }
        if (axlret[*returnSize][i]->right != NULL) {
            axlret[*returnSize + 1][((*axlMat)[*returnSize + 1])++] = \
            axlret[*returnSize][i]->right;
        }
    }
    (*returnSize)++;
    bfs(returnSize, axlMat, axlret);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int* axlMat = malloc(sizeof(int) * maxNum);
    memset(axlMat, 0, sizeof(int) * maxNum);
    struct TreeNode*** axlret = malloc(sizeof(struct TreeNode**) * maxNum);
    axlret[*returnSize] = malloc(sizeof(struct TreeNode*));
    axlret[*returnSize][axlMat[*returnSize]] = root;
    (axlMat[*returnSize])++;
    bfs(returnSize, &axlMat, axlret);
    (*returnColumnSizes) = malloc(sizeof(int) * (*returnSize));
    int** ret = malloc(sizeof(int*) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = axlMat[i];
        ret[i] = malloc(sizeof(int) * axlMat[i]);
        for (int j = 0; j < axlMat[i]; j++) {
            ret[i][j] = axlret[i][j]->val;
        }
        free(axlret[i]);
    }
    free(axlret);
    free(axlMat);
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
    return 0;
}
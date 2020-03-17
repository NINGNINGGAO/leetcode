/*
 * @Author: AGOGIN 
 * @Date: 2020-03-16 18:19:52 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-16 19:54:31
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
        if (i % 2 == 1) {
            for (int k = 0; k < (*returnColumnSizes)[i] / 2; k++) {
                int temp = ret[i][k];
                ret[i][k] = ret[i][(*returnColumnSizes)[i] - 1 - k];
                ret[i][(*returnColumnSizes)[i] - 1 - k] = temp;
            }
        }
        free(axlret[i]);
    }
    free(axlret);
    free(axlMat);
    return ret;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    return levelOrder(root, returnSize, returnColumnSizes);
}

int main() {
    
    return 0;
}
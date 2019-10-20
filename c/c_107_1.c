/*
 * @Author: AGOGIN
 * @Date: 2019-10-19 17:52:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-20 22:37:47
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
#define MAXSIZE 1024
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    (*returnSize) = 0;
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct TreeNode ***res = malloc(sizeof(struct TreeNode**) * MAXSIZE);
    *returnColumnSizes = malloc(sizeof(int) * MAXSIZE);
    int FNum = 1;
    int SNum;
    (*returnColumnSizes)[*returnSize] = FNum;
    res[*returnSize] = malloc(sizeof(struct TreeNode*) * 1);
    res[*returnSize][0] = root;
    while (FNum != 0) {
        (*returnSize)++;
        res[*returnSize] = malloc(sizeof(struct TreeNode*) * MAXSIZE);
        SNum = 0;
        for (int i = 0; i < FNum; i++) {
            if (res[*returnSize - 1][i]->left != NULL) {
                res[*returnSize][SNum++] = res[*returnSize - 1][i]->left;
            }
            if (res[*returnSize - 1][i]->right != NULL) {
                res[*returnSize][SNum++] = res[*returnSize - 1][i]->right;
            }
        }
        FNum = SNum;
        (*returnColumnSizes)[*returnSize] = FNum;
    }
    int** ret = malloc(sizeof(int*) * (*returnSize + 1));
    for (int i = *returnSize - 1; i >= 0; i--) {
        ret[*returnSize - 1 - i] = malloc(sizeof(int) * (*returnColumnSizes)[i]);
        for (int j = 0; j < (*returnColumnSizes)[i]; j++) {
            ret[*returnSize - 1 - i][j] = res[i][j]->val;
        }
        free(res[i]);
    }
    free(res);
    int temp;
    for (int i = 0; i < (*returnSize) / 2; i++) {
        temp = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[*returnSize - 1 - i];
        (*returnColumnSizes)[*returnSize - 1 - i] = temp;
    }
    (*returnSize)++;
    return ret;
}

int main() {
    struct TreeNode a = {15, NULL, NULL};
    struct TreeNode b = {7, NULL, NULL};
    struct TreeNode c = {20, &a, &b};
    struct TreeNode d = {9, NULL, NULL};
    struct TreeNode e = {3, &d, &c};
    int returnSize;
    int* returnColumnSizes;
    int** ret = levelOrderBottom(&e, &returnSize, &returnColumnSizes);
    return 0;
}
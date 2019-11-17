/*
 * @Author: AGOGIN
 * @Date: 2019-11-16 16:38:16
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-16 21:50:59
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
#define maxSize 2048
void dfs(struct TreeNode* root, int depth, double* sum, int* count, int* returnSize) {
    if (root == NULL) return;
    sum[depth] += root->val;
    count[depth]++;
    depth++;
    if (depth > (*returnSize)) (*returnSize) = depth;
    dfs(root->left, depth, sum, count, returnSize);
    dfs(root->right, depth, sum, count, returnSize);
}
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) return NULL;
    double* sum = malloc(sizeof(double) * maxSize);
    int* count = malloc(sizeof(int) * maxSize);
    memset(sum, 0, sizeof(double) * maxSize);
    memset(count, 0, sizeof(int) * maxSize);
    int depth = 0;
    dfs(root, depth, sum, count, returnSize);
    for (int i = 0; i < (*returnSize); i++) {
        sum[i] /= count[i];
    }
    return sum;
}

int main() {
    struct TreeNode a = {15, NULL, NULL};
    struct TreeNode b = {7, NULL, NULL};
    struct TreeNode c = {20, &a,&b};
    struct TreeNode d = {9, NULL, NULL};
    struct TreeNode e = {3, &d, &c};
    int sum = 0;
    double* res = averageOfLevels(&e, &sum);
    for (int i = 0; i < sum; i++) {
        printf("%f\n", res[i]);
    }
    return 0;
}
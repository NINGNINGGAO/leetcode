/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 13:16:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 13:21:31
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
#define maxSize 128
void dfs(struct TreeNode* root, int* arr, int* arrSize) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) arr[(*arrSize)++] = root->val;
    dfs(root->left, arr, arrSize);
    dfs(root->right,arr, arrSize);
}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int* arr1 = malloc(sizeof(int) * maxSize);
    int* arr2 = malloc(sizeof(int) * maxSize);
    int arr1Size = 0, arr2Size = 0;
    dfs(root1, arr1, &arr1Size);
    dfs(root2, arr2, &arr2Size);
    if (arr1Size != arr2Size) return false;
    for (int i = 0; i < arr1Size; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

int main() {

    return 0;
}
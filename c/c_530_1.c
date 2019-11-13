/*
 * @Author: AGOGIN
 * @Date: 2019-11-13 09:38:20
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-13 09:44:54
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
void inOrder(struct TreeNode* root, int* arr, int* arrSize) {
    if (root == NULL) return;
    inOrder(root->left, arr, arrSize);
    arr[(*arrSize)++] = root->val;
    inOrder(root->right, arr, arrSize);
}

int getMinimumDifference(struct TreeNode* root){
    int* arr = malloc(sizeof(int) * 20480);
    int arrSize = 0;
    inOrder(root, arr, &arrSize);
    int res = abs(arr[1] - arr[0]);
    int temp;
    for (int i = 2; i < arrSize; i++) {
        temp = abs(arr[i] - arr[i - 1]);
        if (temp < res) res = temp;
    }
    return res;
}

int main() {

    return 0;
}
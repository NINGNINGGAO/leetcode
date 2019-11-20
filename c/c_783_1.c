/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 15:49:40
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 21:25:39
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
int minDiffArr(int* arr, int arrSize) {
    int res = INT_MAX;
    int temp;
    for (int i = 1; i < arrSize; i++) {
        temp = abs(arr[i] - arr[i - 1]);
        res = temp < res ? temp : res;
    }
    return res;
}
int minDiffInBST(struct TreeNode* root){
    int* arr = malloc(sizeof(int) * 128);
    int arrSize = 0;
    inOrder(root, arr, &arrSize);
    int res = minDiffArr(arr, arrSize);
    return res;
}

int main() {

    return 0;
}
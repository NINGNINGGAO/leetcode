/*
 * @Author: AGOGIN
 * @Date: 2019-11-11 14:53:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-11 19:39:43
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
void inOrder(struct TreeNode* root, int* arr, int* numsSize) {
    if (root == NULL) return;
    inOrder(root->left, arr, numsSize);
    arr[(*numsSize)++] = root->val;
    inOrder(root->right, arr, numsSize);
}
int* findMode(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int* arr = malloc(sizeof(int) * 20480);
    int arrSize = 0;
    inOrder(root, arr, &arrSize);
    int* arrCount = malloc(sizeof(int) * arrSize);
    memset(arrCount, 0, sizeof(int) * arrSize);
    int countNum = 1;
    int maxNum = 0;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] != arr[i - 1]) {
            arrCount[i - 1] = countNum;
            if (countNum > maxNum) maxNum = countNum;
            countNum = 1;
        } else {
            countNum++;
        }
    }
    arrCount[arrSize - 1] = countNum;
    if (countNum > maxNum) maxNum = countNum;
    int* res = malloc(sizeof(int) * 20480);
    for (int i = 0; i < arrSize; i++) {
        if (arrCount[i] == maxNum) res[(*returnSize)++] = arr[i];
    }
    free(arrCount);
    free(arr);
    return res;
}

int main() {
    /*struct TreeNode a = {1,NULL,NULL};
    struct TreeNode b = {1,NULL,&a};
    struct TreeNode c = {4,NULL,NULL};
    struct TreeNode d = {7,NULL,NULL};
    struct TreeNode e = {8,NULL,NULL};
    struct TreeNode f = {3,&b,&c};
    struct TreeNode g = {8,&d,&e};
    struct TreeNode h = {6,&f,&g};*/
    struct TreeNode a = {2,NULL,NULL};
    struct TreeNode b = {2,&a,NULL};
    struct TreeNode h = {1,NULL,&b};
    int num = 0;
    int* res = findMode(&h, &num);
    return 0;
}
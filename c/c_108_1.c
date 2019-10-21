/*
 * @Author: AGOGIN
 * @Date: 2019-10-21 11:26:25
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-21 12:35:09
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

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (numsSize == 0) return NULL;
    int p = 0, q = numsSize - 1;
    int r = (q - p) / 2;
    struct TreeNode* ret = malloc(sizeof(struct TreeNode));
    ret->val = nums[r];
    struct TreeNode* ret_left = sortedArrayToBST(nums + p, p + r);
    struct TreeNode* ret_right = sortedArrayToBST(nums + r + 1, q - r);
    ret->left = ret_left;
    ret->right = ret_right;
    return ret;
}

int main() {

    return 0;
}
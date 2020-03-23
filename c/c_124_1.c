/*
 * @Author: AGOGIN 
 * @Date: 2020-03-22 11:51:29 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-22 15:51:26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int maxSum = INT_MIN;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxGain(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left_gain = Max(maxGain(root->left), 0);
    int right_gain = Max(maxGain(root->right), 0);
    int priceNewPath = root->val + left_gain + right_gain;
    maxSum = Max(maxSum, priceNewPath);
    return root->val + Max(left_gain, right_gain);
}

int maxPathSum(struct TreeNode* root){
    maxGain(root);
    return maxSum;
}

int main() {
    
    return 0;
}
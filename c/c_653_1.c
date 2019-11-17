/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 16:42:30
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 16:48:08
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
#define maxSize 10240
void inOrder(struct TreeNode* root, int* nums, int* numsSize) {
    if (root == NULL) return;
    inOrder(root->left, nums, numsSize);
    nums[(*numsSize)++] = root->val;
    inOrder(root->right, nums, numsSize);
}
bool findTarget(struct TreeNode* root, int k){
    if (root == NULL) return false;
    int* nums = malloc(sizeof(int) * maxSize);
    int numsSize = 0;
    inOrder(root, nums, &numsSize);
    int fast = 0, last = numsSize - 1;
    while (fast < last) {
        if (nums[fast] + nums[last] > k) last--;
        else if (nums[fast] + nums[last] < k) fast++;
        else return true;
    }
    return false;
}

int main() {

    return 0;
}
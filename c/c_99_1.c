/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 15:27:52
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-05 15:28:32
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
int cmp(const void* a, const void* b) {
    long long temp = (long long)(*(int*)a) - (long long)(*(int*)b);
    if (temp == 0) return 0;
    else if (temp < 0) return -1;
    else return 1;
}
void dfs(struct TreeNode* root, int* nums, int* numsSize) {
    if (root == NULL) return;
    dfs(root->left, nums, numsSize);
    nums[(*numsSize)++] = root->val;
    dfs(root->right, nums, numsSize);
}
void isTrueDfs(struct TreeNode* root, int* nums, int* numsSize, int* count) {
    if (root == NULL) return;
    isTrueDfs(root->left, nums, numsSize, count);
    root->val = nums[(*count)++];
    isTrueDfs(root->right, nums, numsSize, count);
}
void recoverTree(struct TreeNode* root){
    int* nums = malloc(sizeof(int) * 2048);
    int numsSize = 0;
    dfs(root, nums, &numsSize);
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0;
    isTrueDfs(root, nums, &numsSize, &count);
}

int main() {

    return 0;
}
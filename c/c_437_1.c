/*
 * @Author: AGOGIN
 * @Date: 2019-11-06 15:50:24
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-06 16:07:21
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
int paths(struct TreeNode* root, int sum) {
    if (root == NULL) return 0;
    int res = 0;
    if (root->val == sum) res++;
    res += paths(root->left, sum - root->val);
    res += paths(root->right, sum - root->val);
    return res;
}
int pathSum(struct TreeNode* root, int sum){
    if (root == NULL) return 0;
    return paths(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int main() {

    return 0;
}
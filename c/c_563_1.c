/*
 * @Author: AGOGIN
 * @Date: 2019-11-14 09:45:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-14 10:15:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define abs(a) ((a) > 0 ? (a) : (-(a)))
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int countNum(struct TreeNode* root, int* res) {
    if (root == NULL) return 0;
    int L = countNum(root->left, res);
    int R = countNum(root->right, res);
    *res += abs(L - R);
    int countRes = L + R + root->val;
    return countRes;
}
int findTilt(struct TreeNode* root){
    if (root == NULL) return 0;
    int res = 0;
    int temp = countNum(root, &res);
    return res;
}

int main() {
    struct TreeNode b = {2, NULL, NULL};
    struct TreeNode c = {3, NULL, NULL};
    struct TreeNode a = {1, &b, &c};
    int res = findTilt(&a);
    return 0;
}
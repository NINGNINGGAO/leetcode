/*
 * @Author: AGOGIN
 * @Date: 2019-10-19 16:33:56
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-19 17:13:06
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int ret = Max(maxDepth(root->left), maxDepth(root->right)) + 1;
    return ret;
};

int main() {

    return 0;
}
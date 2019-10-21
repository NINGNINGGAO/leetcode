/*
 * @Author: AGOGIN
 * @Date: 2019-10-21 12:54:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-21 13:05:30
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

int minDepth(struct TreeNode* root){
    if(root == NULL) return 0;

    int leftnum = minDepth(root->left)+1;
    int rightnum = minDepth(root->right)+1;

    if(root->left == NULL) return rightnum;
    else if(root->right == NULL) return leftnum;
    else if(leftnum <= rightnum) return leftnum;
    else return rightnum;
}
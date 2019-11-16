/*
 * @Author: AGOGIN
 * @Date: 2019-11-16 11:25:08
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-16 11:34:52
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
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if (t1 == NULL) return t2;
    if (t2 == NULL) return t1;
    t1->val += t2->val;
    if (t1->left == NULL) t1->left = t2->left;
    else {
        t1->left = mergeTrees(t1->left, t2->left);
    }
    if (t1->right == NULL) t1->right = t2->right;
    else {
        t1->right = mergeTrees(t1->right, t2->right);
    }
    return t1;
}

int main() {

    return 0;
}
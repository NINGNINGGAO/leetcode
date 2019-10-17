/*
 * @Author: AGOGIN
 * @Date: 2019-10-17 22:10:37
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-17 22:32:37
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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if ((p != NULL && q == NULL) || (p == NULL && q != NULL)) {
        return false;
    }
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p->val != q->val) {
        return false;
    }
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
}

int main() {

    return 0;
}
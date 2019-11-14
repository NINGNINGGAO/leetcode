/*
 * @Author: AGOGIN
 * @Date: 2019-11-14 22:08:18
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-14 22:30:34
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
bool isSameTree(struct TreeNode* s, struct TreeNode* t) {
    if (s == NULL && t == NULL) return true;
    if (s == NULL || t == NULL) return false;
    return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if (s == NULL) return false;
    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main() {

    return 0;
}
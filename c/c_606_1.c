/*
 * @Author: AGOGIN
 * @Date: 2019-11-16 11:05:51
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-16 11:21:00
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

#define maxSize 40960
void preOrder(struct TreeNode* root, char* s) {
    if (root == NULL) return;
    sprintf(s, "%s(%d", s, root->val);
    preOrder(root->left, s);
    if (root->left == NULL && root->right != NULL) {
        sprintf(s, "%s()", s);
    }
    preOrder(root->right, s);
    sprintf(s, "%s)", s);
}
char * tree2str(struct TreeNode* t){
    if (t == NULL) return "";
    char* res = malloc(sizeof(char) * maxSize);
    memset(res, 0, sizeof(char) * maxSize);
    preOrder(t, res);
    int i = 1;
    while (res[i] != '\0') {
        res[i - 1] = res[i];
        i++;
    }
    res[i - 2] = '\0';
    return res;
}

int main() {

    return 0;
}
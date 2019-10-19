/*
 * @Author: AGOGIN
 * @Date: 2019-10-19 17:12:53
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-19 17:26:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int ret = 0;
    struct TreeNode **F, **S, **temp;
    struct TreeNode *a[1024], *b[1024];
    int FNum = 1, SNum = 0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    a[0] = root;
    F = a, S= b;
    while (FNum != 0) {
        SNum = 0;
        for (int i = 0; i < FNum; i++) {
            if (F[i]->left != NULL) {
                S[SNum++] = F[i]->left;
            }
            if (F[i]->right != NULL) {
                S[SNum++] = F[i]->right;
            }
        }
        FNum = SNum;
        temp = F;
        F = S;
        S = temp;
        ret++;
    }
    return ret;
};

int main() {

    return 0;
}
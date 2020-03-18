/*
 * @Author: AGOGIN 
 * @Date: 2020-03-18 17:27:21 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-18 19:33:52
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

void flatten(struct TreeNode* root){
    while (root != NULL) {
        if (root->left == NULL) {
            root = root->right;
        } else {
            struct TreeNode *temp = root->right, *mid = root;
            root->right = root->left;
            root->left = NULL;
            while (mid->right != NULL) {
                mid = mid->right;
            }
            mid->right = temp;
            root = root->right;
        }
    }
}

int main() {
    
    return 0;
}
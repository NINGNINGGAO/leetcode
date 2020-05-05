/*
 * @Author: AGOGIN 
 * @Date: 2020-05-05 11:20:25 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-05-05 11:30:41
 */
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isValidBackTrack(TreeNode* root, long long lower, long long upper) {
        if (root == NULL) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return isValidBackTrack(root->left, lower, root->val) && isValidBackTrack(root->right, root->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBackTrack(root, LONG_MIN, LONG_MAX);
    }
};
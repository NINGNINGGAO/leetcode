/*
 * @Author: AGOGIN 
 * @Date: 2020-04-22 22:21:51 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-22 23:14:34
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;
        int current = 0, next = 0;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        current++;
        while (!nodeQueue.empty()) {
            if (nodeQueue.front()->left != NULL) {
                nodeQueue.push(nodeQueue.front()->left);
                next++;
            }
            if (nodeQueue.front()->right != NULL) {
                nodeQueue.push(nodeQueue.front()->right);
                next++;
            }
            if (current == 1) ret.push_back(nodeQueue.front()->val);
            nodeQueue.pop();
            current--;
            if (current == 0) {
                current = next;
                next = 0;
            }
        }
        return ret;
    }
};
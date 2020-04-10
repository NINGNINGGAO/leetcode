/*
 * @Author: AGOGIN 
 * @Date: 2020-04-09 09:13:47 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-09 09:27:18
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
    void backTrack(vector<string>& ret, string& current, int left, int right, int n) {
        if (current.size() == 2 * n) {
            ret.push_back(current);
            return;
        }
        if (left < n) {
            current.push_back('(');
            backTrack(ret, current, left + 1, right, n);
            current.pop_back();
        }
        if (right < left) {
            current.push_back(')');
            backTrack(ret, current, left, right + 1, n);
            current.pop_back();
        } 
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string current;
        backTrack(ret, current, 0, 0, n);
        return ret;
    }
};
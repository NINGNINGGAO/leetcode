/*
 * @Author: AGOGIN 
 * @Date: 2020-04-25 14:25:39 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-25 15:24:22
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void backTrack(vector<vector<int>>& ret, vector<int>& nums, 
    vector<bool>& flag, vector<int>& temp) {
        int numsSize = nums.size();
        if (temp.size() == numsSize) {
            ret.push_back(temp);
            return;
        }
        for (int i = 0; i < numsSize; i++) {
            if (flag[i] == 0) {
                flag[i] = 1;
                temp.push_back(nums[i]);
                backTrack(ret, nums, flag, temp);
                temp.pop_back();
                flag[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int numsSize = nums.size();
        vector<vector<int> > ret;
        vector<bool> flag(numsSize, false);
        vector<int> temp;
        backTrack(ret, nums, flag, temp);
        return ret;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int> > ret = s.permute(nums);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[0].size(); j++) {
            cout << ret[i][j];
        }
        cout << endl;
    }
}
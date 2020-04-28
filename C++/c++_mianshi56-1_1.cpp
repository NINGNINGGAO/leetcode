/*
 * @Author: AGOGIN 
 * @Date: 2020-04-28 16:44:23 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-28 16:51:38
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0;
        for (int n : nums) temp ^= n;
        int bit = 1;
        while ((temp & bit) == 0) bit <<= 1;
        int a = 0, b = 0;
        for (int n : nums) {
            if ((n & bit) == 0) a ^= n;
            else b ^= n;
        }
        return vector<int>{a, b};
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,10,4,1,4,3,3};
    vector<int> ret = s.singleNumbers(nums);
    cout << ret[0] << "\t" << ret[1] << endl;
}
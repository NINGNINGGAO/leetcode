/*
 * @Author: AGOGIN 
 * @Date: 2020-05-03 10:23:15 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-05-03 10:50:07
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (sum > 0) sum += num;
            else sum = num;
            ret = max(ret, sum);
        }
        return ret;
    }
};
/*
 * @Author: AGOGIN 
 * @Date: 2020-04-17 00:15:46 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-17 00:31:13
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int numsSize = nums.size();
        int rightMost = 0;
        for (int i = 0; i < numsSize; i++) {
            if (i <= rightMost) {
                rightMost = max(rightMost, nums[i] + i);
                if (rightMost >= numsSize - 1) return true;
            }
        }
        return false;
    }
};
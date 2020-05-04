/*
 * @Author: AGOGIN 
 * @Date: 2020-05-04 15:37:26 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-05-04 15:41:48
 */
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int numsSize = nums.size();
        int ret = 0;
        int bound = 0;
        int maxPosition = 0;
        for (int i = 0; i < numsSize - 1; i++) {
            maxPosition = max(maxPosition, i + nums[i]);
            if (i == bound) {
                bound = maxPosition;
                ret++;
            }
        }
        return ret;
    }
};
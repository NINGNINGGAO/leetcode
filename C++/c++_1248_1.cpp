/*
 * @Author: AGOGIN 
 * @Date: 2020-04-21 12:21:55 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-21 12:36:00
 */
#include <vector>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int numsSize = nums.size();
        vector<int> arr;
        arr.push_back(-1);
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] % 2 == 1) arr.push_back(i);
        }
        arr.push_back(numsSize);//将-1与numsSize push，用于处理边界条件
        int arrSize = arr.size();
        int ret = 0;
        if (arrSize - 2 < k) return ret;
        for (int i = 1; i < arrSize - k; i++) {
            ret += (arr[i] - arr[i - 1]) * (arr[i + k] - arr[i + k - 1]);
        }
        return ret;
    }
};
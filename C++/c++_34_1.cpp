/*
 * @Author: AGOGIN 
 * @Date: 2020-04-11 22:42:21 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-11 22:52:32
 */
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else right = mid - 1;
        }
        if (left >= nums.size() || nums[left] != target) ret.push_back(-1);
        else ret.push_back(left);
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        if (right < 0 || nums[right] != target) ret.push_back(-1);
        else ret.push_back(right);
        return ret;
    }
};
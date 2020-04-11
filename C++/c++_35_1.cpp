/*
 * @Author: AGOGIN 
 * @Date: 2020-04-11 21:05:55 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-11 22:06:49
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,5,6};
    int ret = s.searchInsert(nums, 5);
    cout << ret << endl;
}
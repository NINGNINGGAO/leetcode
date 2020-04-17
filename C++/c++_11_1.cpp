/*
 * @Author: AGOGIN 
 * @Date: 2020-04-18 00:14:05 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-18 00:20:01
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int fast = 0;
        int last = height.size() - 1;
        while (fast < last) {
            int temp = min(height[fast], height[last]);
            ret = max(ret, temp * (last - fast));
            if (height[fast] < height[last]) fast++;
            else last--;
        }
        return ret;
    }
};
/*
 * @Author: AGOGIN 
 * @Date: 2020-04-04 07:18:25 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-04 07:57:54
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int hLen = height.size();
        if (hLen <= 2) return ret;
        vector<int> maxLeft(hLen), maxRight(hLen);
        maxLeft[0] = height[0];
        for (int i = 1; i < hLen; i++) maxLeft[i] = max(maxLeft[i - 1], height[i]);
        maxRight[hLen - 1] = height[hLen - 1];
        for (int i = hLen - 2; i >= 0; i--) maxRight[i] = max(maxRight[i + 1], height[i]);
        for (int i = 0; i < hLen; i++) {
            ret += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return ret;
    }
};
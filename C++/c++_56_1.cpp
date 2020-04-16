/*
 * @Author: AGOGIN 
 * @Date: 2020-04-16 14:17:06 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-16 14:31:22
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ret[ret.size() - 1][1] >= intervals[i][0]) {
                ret[ret.size() - 1][1] = max(ret[ret.size() - 1][1], intervals[i][1]);
            } else ret.push_back(intervals[i]);
        }
        return ret;
    }
};
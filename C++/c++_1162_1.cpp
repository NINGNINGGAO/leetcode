/*
 * @Author: AGOGIN 
 * @Date: 2020-04-04 15:10:03 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-04 15:27:48
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int INF;
    Solution() : INF(1222) {}
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        vector<vector<int> > dpF(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j <col; j++) {
                dpF[i][j] = grid[i][j] ? 0 : INF;
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) continue;
                if (i > 0) dpF[i][j] = min(dpF[i][j], dpF[i - 1][j] + 1);
                if (j > 0) dpF[i][j] = min(dpF[i][j], dpF[i][j - 1] + 1);
            }
        }
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (grid[i][j]) continue;
                if (i < row - 1) dpF[i][j] = min(dpF[i][j], dpF[i + 1][j] + 1);
                if (j < col - 1) dpF[i][j] = min(dpF[i][j], dpF[i][j + 1] + 1);
            }
        }
        int ret = -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) continue;
                ret = max(ret, dpF[i][j]);
            }
        }
        if (ret == INF) return -1;
        return ret;
    }
};
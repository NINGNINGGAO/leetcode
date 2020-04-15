/*
 * @Author: AGOGIN 
 * @Date: 2020-04-15 13:36:45 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-15 13:51:14
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, INT16_MAX));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) dp[i][j] = 0;
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j <col; j++) {
                if (i != 0) dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                if (j != 0) dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            }
        }
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (i != row - 1) dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
                if (j != col - 1) dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
            }
        }
        return dp;
    }
};
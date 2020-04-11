/*
 * @Author: AGOGIN 
 * @Date: 2020-04-11 19:03:29 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-11 22:31:40
 */
#include <vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int> > dp(N + 1, vector<int>(K + 1, 0));
        for (int i = 1; i <= N; i++) dp[i][1] = i;
        for (int i = 1; i <= K; i++) dp[1][i] = 1;
        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= K; j++) {
                int left = 1;
                int right = i;
                while (left < right) {
                    int mid = left + (right - left + 1) / 2;
                    int breakCount = dp[mid - 1][j - 1];
                    int notBreakCount = dp[i - mid][j];
                    if (breakCount > notBreakCount) right = mid - 1;
                    else left = mid;
                }
                dp[i][j] = max(dp[left - 1][j - 1], dp[i - left][j]) + 1;
            }
        }
        return dp[N][K];
    }
};
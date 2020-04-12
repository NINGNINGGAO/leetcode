/*
 * @Author: AGOGIN 
 * @Date: 2020-04-11 22:53:35 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-11 23:00:10
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
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    int breakCount = dp[mid - 1][j - 1];
                    int notBreakCount = dp[i - mid][j];
                    if (breakCount > notBreakCount) right = mid - 1;
                    else if (breakCount < notBreakCount) left = mid + 1;
                    else right = mid - 1;
                }
                dp[i][j] = max(dp[left - 1][j - 1], dp[i - left][j]) + 1;
            }
        }
        return dp[N][K];
    }
};
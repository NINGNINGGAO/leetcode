/*
 * @Author: AGOGIN 
 * @Date: 2020-04-06 09:34:05 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-06 10:43:54
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1Len = word1.size();
        int w2Len = word2.size();
        if (w1Len * w2Len == 0) return w1Len + w2Len;
        vector<vector<int> > dp(w1Len + 1, vector<int>(w2Len + 1, 0));
        for (int i = 0; i <= w2Len; i++) dp[0][i] = i;
        for (int i = 1; i <= w1Len; i++) dp[i][0] = i;
        for (int i = 1; i <= w1Len; i++) {
            for (int j = 1; j <= w2Len; j++) {
                if (word1[i - 1] != word2[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[w1Len][w2Len];
    }
};

int main() {
    string word1 = "zoologicoarchaeologist";
    string word2 = "zoogeologist";
    Solution s;
    int ret = s.minDistance(word1, word2);
    cout << ret << endl;
}
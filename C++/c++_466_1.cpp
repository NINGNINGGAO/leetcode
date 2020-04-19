/*
 * @Author: AGOGIN 
 * @Date: 2020-04-19 13:46:51 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-19 14:03:31
 */
#include <string>
#include <unordered_map>
#include <pair>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        int s1Cnt = 0, s2Cnt = 0, index = 0;
        unordered_map<int, pair<int, int> > recall;
        pair<int, int> preLoop, inLoop;
        while (true) {
            ++s1Cnt;
            for (char ch : s1) {
                if (ch == s2[index]) {
                    index++;
                    if (index == s2.size()) {
                        s2Cnt++;
                        index = 0;
                    }
                }
            }
            if (s1Cnt == n1) return s2Cnt / n2;
            if (recall.count(index)) {
                auto [s1CntPrime, s2CntPrime] = recall[index];
                preLoop = {s1CntPrime, s2CntPrime};
                inLoop = {s1Cnt - s1CntPrime, s2Cnt - s2CntPrime};
                break;
            } else recall[index] = {s1Cnt, s2Cnt};
        }
        int ans = preLoop.second + (n1 - preLoop.first) / inLoop.first * inLoop.second;
        int rest = (n1 - preLoop.first) % inLoop.first;
        for (int i = 0; i < rest; i++) {
            for (char ch : s1) {
                if (ch == s2[index]) {
                    index++;
                    if (index == s2.size()) {
                        ans++;
                        index = 0;
                    }
                }
            }
        }
        return ans / n2;
    }
};
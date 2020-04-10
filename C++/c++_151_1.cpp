/*
 * @Author: AGOGIN 
 * @Date: 2020-04-10 16:44:54 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-10 17:27:16
 */
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int sLen = s.size();
        int idx = 0;
        for (int start = 0; start < sLen; start++) {
            if (s[start] != ' ') {
                if (idx != 0) s[idx++] = ' ';
                int end = start;
                while (end < sLen && s[end] != ' ') s[idx++] = s[end++];
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
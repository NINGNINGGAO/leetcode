/*
 * @Author: AGOGIN 
 * @Date: 2020-04-03 19:39:34 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-03 19:58:20
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
class Automaton {
private:
    string state;
    map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int getCol(char c) {
        if (isspace(c)) return 0;
        else if (c == '+' || c == '-') return 1;
        else if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign;
    long long ret;
    Automaton() :state("start"), sign(1), ret(0){}
    void get(char c) {
        state = table[state][getCol(c)];
        if (state == "in_number") {
            ret = ret * 10 + (c - '0');
            ret = (sign == 1 ? min(ret, (long long)INT_MAX) : min(ret, -(long long)INT_MIN));
        } else if (state == "signed") sign = (c == '+' ? 1 : -1);
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automation;
        for (char c : str) automation.get(c);
        return automation.sign * automation.ret;
    }
};

int main() {
    Solution s;
    string num = "   -42";
    cout << s.myAtoi(num);
    return 0;
}
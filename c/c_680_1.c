/*
 * @Author: AGOGIN
 * @Date: 2019-11-17 18:41:56
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-17 18:57:30
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isPalindrome(char * s, int begin, int end) {
    int fast = begin, last = end;
    while (fast < last) {
        if (s[fast] == s[last]) {
            fast++;
            last--;
        } else return false;
    }
    return true;
}
bool validPalindrome(char * s){
    int sLen = strlen(s);
    int fast = 0, last = sLen - 1;
    if (isPalindrome(s, fast, last) == true) return true;
    while (fast < last) {
        if (s[fast] == s[last]) {
            fast++;
            last--;
        } else return isPalindrome(s, fast + 1, last) || isPalindrome(s, fast, last - 1);
    }
    return true;
}

int main() {
    char s[] = "abca";
    bool res = validPalindrome(s);
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-10-22 16:43:15
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-22 22:13:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

bool isPalindrome(char * s){
    int num = 0;
    while (s[num] != '\0') {
        num++;
    }
    if (num == 0) return true;
    int p = 0, q = num - 1;
    int flag, mid = 0;
    while (p < q) {
        flag = 0;
        if ((s[p] < 'a' || s[p] > 'z') && (s[p] < 'A' || s[p] > 'Z') && (s[p] < '0' || s[p] > '9')) {
            p++;
            flag = 1;
        }
        if ((s[q] < 'a' || s[q] > 'z') && (s[q] < 'A' || s[q] > 'Z') && (s[q] < '0' || s[q] > '9')) {
            q--;
            flag = 1;
        }
        if (flag == 0) {
            if (s[p] == s[q] || (s[p] + 32 == s[q] && s[p] >= 65) || (s[p] - 32 == s[q] && s[p] >= 97)) {
                p++;
                q--;
            } else {
                mid = 1;
                break;
            }
        }
    }
    if (mid == 1) {
        return false;
    }
    return true;
}

int main() {
    char s[] = "0P";
    bool ret = isPalindrome(s);
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-27 17:38:16
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-27 17:54:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int longestValidParentheses(char * s){
    int sLen = strlen(s);
    int* arr = malloc(sizeof(int) * (sLen + 1));
    int count = 0;
    arr[count++] = -1;
    int res = 0;
    for (int i = 0; i < sLen; i++) {
        if (s[i] == '(') {
            arr[count++] = i;
        } else {
            count--;
            if (count == 0) arr[count++] = i;
            else res = res > (i - arr[count - 1]) ? res : (i - arr[count - 1]);
        }
    }
    return res;
}

int main() {
    char s[] = ")()())";
    int res = longestValidParentheses(s);
    return 0;
}
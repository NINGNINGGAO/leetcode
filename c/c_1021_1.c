/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 13:10:23
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 13:23:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * removeOuterParentheses(char * S){
    int count = 0;
    int sLen = strlen(S);
    if (sLen == 0) return "";
    int* flag = malloc(sizeof(int) * sLen);
    memset(flag, 0, sizeof(int) * sLen);
    for (int i = 0; i < sLen; i++) {
        if (count == 0) flag[i] = 1;
        if (S[i] == '(') count++;
        else if (S[i] == ')') {
            count--;
            if (count == 0) flag[i] = 1;
        }
    }
    char* res = malloc(sizeof(char) * sLen);
    memset(res, 0, sizeof(char) * sLen);
    for (int i = 0; i < sLen; i++) {
        if (flag[i] == 0) sprintf(res, "%s%c", res, S[i]);
    }
    return res;
}

int main() {
    char S[] = "(()())(())";
    char* res = removeOuterParentheses(S);
    return 0;
}
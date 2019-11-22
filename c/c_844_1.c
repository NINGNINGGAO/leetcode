/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 22:32:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 22:40:38
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool backspaceCompare(char * S, char * T){
    int sLen = strlen(S), tLen = strlen(T);
    int sCount = 0, tCount = 0;
    for (int i = 0; i < sLen; i++) {
        if (isalpha(S[i])) {
            S[sCount++] = S[i];
        } else {
            if (sCount > 0) sCount--;
        }
    }
    S[sCount] = '\0';
    for (int i = 0; i < tLen; i++) {
        if (isalpha(T[i])) {
            T[tCount++] = T[i];
        } else {
            if (tCount > 0) tCount--;
        }
    }
    T[tCount] = '\0';
    return !strcmp(S, T);
}

int main() {
    char S[] = "ad#c";
    char T[] = "ab#c";
    bool res = backspaceCompare(S, T);
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 22:14:18
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 22:27:44
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * reverseOnlyLetters(char * S){
    int sLen = strlen(S);
    int fast = 0, last = sLen - 1;
    char temp;
    while (fast < last) {
        while (isalpha(S[fast]) == 0) {
            fast++;
            if (fast >= sLen) return S;
        }
        while (isalpha(S[last]) == 0) {
            last--;
            if (last < 0) return S;
        }
        if (fast < last) {
            temp = S[fast];
            S[fast++] = S[last];
            S[last--] = temp;
        } else return S;
    }
    return S;
}

int main() {
    char S[] = "?6C40E";
    char* res = reverseOnlyLetters(S);
    printf("%s\n", res);
    return 0;
}
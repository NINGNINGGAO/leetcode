/*
 * @Author: AGOGIN 
 * @Date: 2020-04-10 17:28:44 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-10 17:37:08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

void reverse(char* s, int begin, int end) {
    int p = begin, q = end - 1;
    while (p < q) {
        char temp = s[p];
        s[p++] = s[q];
        s[q--] = temp;
    }
}

char * reverseWords(char * s){
    int sLen = strlen(s);
    reverse(s, 0, sLen);
    int idx = 0;
    for (int start = 0; start < sLen; start++) {
        if (s[start] != ' ') {
            if (idx != 0) s[idx++] = ' ';
            int end = start;
            while (end < sLen && s[end] != ' ') s[idx++] = s[end++];
            reverse(s, idx - (end - start), idx);
            start = end;
        }
    }
    s[idx] = '\0';
    return s;
}

int main() {
    char s[] = "the sky is blue";
    char* ret = reverseWords(s);
    printf("%s\n", ret);
    return 0;
}
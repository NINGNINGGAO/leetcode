/*
 * @Author: AGOGIN
 * @Date: 2019-12-07 17:17:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-07 17:48:22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void backTrack(char* s, int sLen, int flag, int* res) {
    if (flag == sLen) (*res)++;
    else {
        if (s[flag] == '0') return;
        backTrack(s,sLen, flag + 1, res);
        if (flag + 2 > sLen) return;
        if (s[flag] > '2') return;
        if (s[flag] == '2' && s[flag + 1] > '6') return;
        backTrack(s, sLen, flag + 2, res);
    }
}
int numDecodings(char * s){
    int res = 0;
    int sLen = strlen(s);
    if (sLen == 0) return res;
    backTrack(s, sLen, 0, &res);
    return res;
}

int main() {
    char s[] = "7541387519572282368613553811323167125532172369624572591562685959575371877973171856836975137559677665";
    int res = numDecodings(s);
    printf("%d\n", res);
    return 0;
}
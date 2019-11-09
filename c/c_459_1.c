/*
 * @Author: AGOGIN
 * @Date: 2019-11-08 17:09:50
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-09 12:04:27
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool repeatedSubstringPattern(char * s){
    int len = strlen(s);
    int i=0,t=0;
    for(t = 1; t <= len / 2; ++t)
    {
        if (len % t) continue;
        for (i = t; i < len && s[i % t] == s[i]; ++i);
        if (i == len) return true;
    }
    return false;
}

int main() {
    char* s = "ababba";
    bool res = repeatedSubstringPattern(s);
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-10-31 13:11:41
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-31 13:18:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isAnagram(char * s, char * t){
    int sHash[26], tHash[26];
    int sLen = 0, tLen = 0;
    memset(sHash, 0, sizeof(sHash));
    memset(tHash, 0, sizeof(tHash));
    while (*s != '\0') {
        sHash[*s - 'a']++;
        s++;
        sLen++;
    }
    while (*t != '\0') {
        tHash[*t - 'a']++;
        t++;
        tLen++;
    }
    if (sLen != tLen) return false;
    else {
        for (int i = 0; i < 26; i++) {
            if (sHash[i] != tHash[i]) return false;
        }
        return true;
    }
}

int main() {

    return 0;
}
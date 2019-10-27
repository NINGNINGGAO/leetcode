/*
 * @Author: AGOGIN
 * @Date: 2019-10-27 22:00:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-27 22:13:47
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isIsomorphic(char * s, char * t){
    char a[128] = {0};
    char b[128] = {0};
    for (int i = 0; s[i] != 0; ++i) {
        a[s[i]] += i + 1;
        b[t[i]] += i + 1;
        if (a[s[i]] != b[t[i]]) return false;
    }
    return true;
}

int main() {

    return 0;
}
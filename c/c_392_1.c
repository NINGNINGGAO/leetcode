/*
 * @Author: AGOGIN
 * @Date: 2019-11-04 16:27:49
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-04 17:10:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isSubsequence(char * s, char * t){
    if (strlen(s) == 0) return true;
    if (strlen(t) == 0) return false;
    int i = 0, j = 0;
    while (s[i] != '\0') {
        while (t[j] != '\0' && t[j] != s[i]) {
            j++;
        }
        if (t[j] == '\0') return false;
        i++;
        j++;
    }
    return true;
}

int main() {

    return 0;
}
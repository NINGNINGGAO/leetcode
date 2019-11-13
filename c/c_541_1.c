/*
 * @Author: AGOGIN
 * @Date: 2019-11-13 11:38:06
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-13 11:43:36
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void overTurn(char* s, int fast, int last) {
    int i = fast, j = last -1;
    while (i < j) {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
        i++;
        j--;
    }
}
char * reverseStr(char * s, int k){
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k) {
        if (i + k <= len) overTurn(s, i, i + k);
        else overTurn(s, i, len);
    }
    return s;
}

int main() {

    return 0;
}
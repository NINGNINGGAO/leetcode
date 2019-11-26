/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 15:36:27
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 15:38:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int balancedStringSplit(char * s){
    int count = 0;
    int res = 0;
    int sLen = strlen(s);
    for (int i = 0; i < sLen; i++) {
        if (s[i] == 'R') count++;
        else count--;
        if (count == 0) res++;
    }
    return res;
}

int main() {

    return 0;
}
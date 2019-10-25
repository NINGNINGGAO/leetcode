/*
 * @Author: AGOGIN
 * @Date: 2019-10-25 19:52:50
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-25 20:42:56
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define system 26
int titleToNumber(char * s){
    if (s == NULL || *s == 0) return NULL;
    int len = 0;
    while (s[len] != 0) {
        len++;
    }
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret = ret * system + (int)(s[i] - 'A' + 1);
    }
    return ret;
}

int main() {

    return 0;
}
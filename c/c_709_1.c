/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 21:49:17
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 21:50:50
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * toLowerCase(char * str){
    int sLen = strlen(str);
    for (int i = 0; i < sLen; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str;
}

int main() {

    return 0;
}
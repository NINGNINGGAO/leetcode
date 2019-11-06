/*
 * @Author: AGOGIN
 * @Date: 2019-11-06 15:26:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-06 15:37:55
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isBS(char s) {
    if (s == ' ') return true;
    return false;
}
int countSegments(char * s){
    int res = 0, flag = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (flag == 0 && isBS(s[i]) == false) {
            flag = 1;
            res++;
        }
        if (isBS(s[i]) == true) flag = 0;
        i++;
    }
    return res;
}

int main() {
    char* s = "love live! mu'sic forever";
    int res = countSegments(s);
    return 0;
}
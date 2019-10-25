/*
 * @Author: AGOGIN
 * @Date: 2019-10-25 11:10:50
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-10-25 19:44:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define system 26
char * convertToTitle(int n){
    int len = 0, temp = n;
    while (temp) {
        len++;
        temp = (temp - 1) / system;
    }
    char* ret = malloc(sizeof(int) * (len + 1));
    temp = n;
    ret[len] = 0;
    while (len--) {
        ret[len] = (temp - 1) % system + 'A';
        temp = (temp - 1) / system;
    }
    return ret;
}

int main() {
    char* ret = convertToTitle(26*26);
    return 0;
}
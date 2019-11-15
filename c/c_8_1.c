/*
 * @Author: AGOGIN
 * @Date: 2019-11-15 17:36:30
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-15 17:39:11
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


int main() {

    return 0;
}

int myAtoi(char * str){
    int numlen = strlen(str);
    int i = 0;

    while (str[i] == ' ') {
        i++;
    }

    int flag = 1;
    double res = 0;
    int bit = 0;

    if (str[i] == '-') {
        i++;
        flag = -1;
    } else if (str[i] == '+') {
        i++;
        flag = 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        bit = (int)(str[i] - '0');
        res = res * 10 + bit;
        if (flag == 1) {
            if (res >= INT_MAX) {
            return INT_MAX;
            }
        } else {
            if (res > -(INT_MIN + 1)) {
            return INT_MIN;
            }
        }
        i++;

    }

    res = (int)res;
    if (flag == -1) {
        return -res;
    } else {
        return res;
    }
}


/*
 * @Author: AGOGIN
 * @Date: 2019-09-09 16:54:28
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-07 17:17:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int numDecodings(char * s){
    int num = 0;
    while (s[num] != '\0') num++;
    unsigned int arr[num];
    int temp, mid;
    if (s[0] <= '9' && s[0] > '0') {
        arr[0] = 1;
    } else {
        return 0;
    }
    if (num < 2) return arr[0];
    mid = (s[1] - '0');
    temp = (s[0] - '0') * 10 + mid;
    if (mid != 0) {
        if (temp < 27) {
            arr[1] = arr[0] + 1;
        } else {
            arr[1] = arr[0];
        }
    } else {
        if (temp > 26) {
            return 0;
        }
        arr[1] = 1;
    }
    int i = 2;
    while (i < num) {
        mid = s[i] - '0';
        temp = (s[i - 1] - '0') * 10 + mid;
        if (mid != 0) {
            if (temp < 27 && temp > 10) {
                arr[i] = arr[i - 1] + arr[i - 2];
            } else {
                arr[i] = arr[i - 1];
            }
        } else {
            if (temp == 0) {
                return 0;
            } else if (temp > 26) {
                return 0;
            }
            arr[i] = arr[i - 2];
        }
        i++;
    }
    return arr[num - 1];
}

int main() {
    char* s = "301";
    int ret = numDecodings(s);
    printf("%d\n", ret);
    return 0;
}
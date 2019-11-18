/*
 * @Author: AGOGIN
 * @Date: 2019-11-18 16:27:59
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-18 17:13:21
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))
int countBinarySubstrings(char * s){
    int sLen = strlen(s);
    int res = 0;
    if (sLen <= 1) return res;
    int* arr = malloc(sizeof(int) * 3);
    memset(arr, 0, sizeof(int) * 3);
    char flag = s[arr[0]];
    int i;
    for (i = 1; i < sLen; i++) {
        if (flag != s[i]) {
            arr[1] = i;
            break;
        }
    }
    for (i; i < sLen; i++) {
        if (flag == s[i]) {
            arr[2] = i;
            res += Min(arr[1] - arr[0], arr[2] - arr[1]);
            arr[0] = arr[1];
            arr[1] = arr[2];
            flag = s[arr[0]];
        }
    }
    res += Min(arr[1] - arr[0], sLen - arr[1]);
    return res;
}

int main() {
    char s[] = "00110";
    int res = countBinarySubstrings(s);
    return 0;
}
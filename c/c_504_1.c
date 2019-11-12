/*
 * @Author: AGOGIN
 * @Date: 2019-11-12 11:03:48
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-12 11:21:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void reverseString(char* s, int sSize){
    for(int i = 0;i < sSize / 2; i++){
        int t = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = t;
    }
}
char * convertToBase7(int num){
    if (num == 0) return "0";
    int flag = 0;
    if (num < 0) {
        flag = 1;
        num = -num;
    }
    char* res = malloc(sizeof(char) * 15);
    res[0] = '\0';
    while (num != 0) {
        sprintf(res, "%s%d", res, num % 7);
        num /= 7;
    }
    if (flag == 1) sprintf(res, "%s-", res);
    reverseString(res, strlen(res));
    return res;
}

int main() {
    int num = -7;
    char* res = convertToBase7(num);
    return 0;
}
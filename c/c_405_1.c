/*
 * @Author: AGOGIN
 * @Date: 2019-11-05 09:41:20
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-05 10:20:49
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * toHex(int num){
    char map[] = "0123456789abcdef";
    char* res = malloc(sizeof(char) * 9);
    res[0] = '\0';
    if (num == 0) {
        sprintf(res, "%s%d", res, 0);
        return res;
    }
    unsigned int n = num;
    char temp;
    while (n != 0) {
        temp = map[n % 16];
        n /= 16;
        sprintf(res, "%s%c", res, temp);
    }
    int head = 0, last = strlen(res) - 1;
    while (head < last) {
        temp = res[head];
        res[head++] = res[last];
        res[last--] = temp;
    }
    return res;
}

int main() {
    char* res = toHex(26);
    return 0;
}
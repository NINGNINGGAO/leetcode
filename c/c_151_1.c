/*
 * @Author: AGOGIN 
 * @Date: 2020-04-10 11:55:35 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-10 16:00:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void flipWords(char* s, int sLen, int front, int after, int* now) {
    int p = front, q = after - 1;
    while (p < q) {
        char temp = s[p];
        s[p++] = s[q];
        s[q--] = temp;
    }
    for (int i = front; i < after; i++) s[(*now)++] = s[i];
    if (*now < sLen) s[(*now)++] = ' ';
}

char * reverseWords(char * s){
    int sLen = strlen(s);
    if (sLen == 0) return s;
    for (int i = 0; i < sLen / 2; i++) {
        char temp = s[i];
        s[i] = s[sLen - 1 - i];
        s[sLen - 1 - i] = temp;
    }
    int front = 0, end = sLen - 1, after, now = 0;
    while (front < sLen && s[front] == ' ') front++;
    while (end >= 0 && s[end] == ' ') end--;
    s[end + 1] = '\0';
    while (front <= end) {
        after = front;
        while (s[after] != ' ' && s[after] != '\0') after++;
        flipWords(s, sLen, front, after, &now);
        front = after;
        while (s[front] == ' ') front++;
    }
    if (now - 1 >= 0 && s[now - 1] == ' ') s[now - 1] = '\0';
    else s[now] = '\0';
    return s;
}

int main() {
    char s[] = " ";
    char* ret = reverseWords(s);
    printf("%s\n", ret);
    return 0;
}
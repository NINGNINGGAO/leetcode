/*
 * @Author: AGOGIN
 * @Date: 2019-11-07 10:06:30
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-07 10:54:15
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void addNum(char* chars, int* slow, int num) {
    if (num != 1) {
        int s = *slow;
        while (num != 0) {
            int temp = num % 10;
            chars[(*slow)++] = temp + '0';
            num /= 10;
        }
        int p = (*slow) - 1;
        char temp;
        while (s < p) {
            temp = chars[s];
            chars[s++] = chars[p];
            chars[p--] = temp;
        }
    }
}
int compress(char* chars, int charsSize){
    int slow = 0;
    int flag = 0;
    int num = 1;
    for (int i = 1; i < charsSize; i++) {
        if (chars[i] == chars[i - 1]) num++;
        else {
            chars[slow++] = chars[i - 1];
            addNum(chars, &slow, num);
            num = 1;
        }
    }
    chars[slow++] = chars[charsSize - 1];
    addNum(chars, &slow, num);
    return slow;
}

int main() {
    char chars[] = "aaabbaa";
    int res = compress(chars, 7);
    return 0;
}
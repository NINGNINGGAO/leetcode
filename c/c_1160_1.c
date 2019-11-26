/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 22:37:28
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 22:48:06
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int countCharacters(char ** words, int wordsSize, char * chars){
    int temp[26] = {0};
    int* mid = malloc(sizeof(int) * 26);
    int sLen = strlen(chars);
    for (int i = 0; i < sLen; i++) {
        temp[chars[i] - 'a']++;
    }
    int res = 0;
    int flag;
    for (int i = 0; i < wordsSize; i++) {
        flag = 0;
        memset(mid, 0, sizeof(int) * 26);
        for (int j = 0; j < strlen(words[i]); j++) {
            mid[words[i][j] - 'a']++;
        }
        for (int k = 0; k < 26; k++) {
            if (temp[k] - mid[k] < 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) res += strlen(words[i]);
    }
    return res;
}

int main() {

    return 0;
}
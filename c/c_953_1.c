/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 17:24:59
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 17:49:15
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isAlienSorted(char ** words, int wordsSize, char * order){
    char map[26] = {0};
    for (int i = 0; i < strlen(order); i++) {
        map[order[i] - 'a'] = i + 'a';
    }
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            words[i][j] = map[words[i][j] - 'a'];
        }
    }
    for (int i = 1; i < wordsSize; i++) {
        if (strcmp(words[i - 1], words[i]) > 0) return false;
    }
    return true;
}

int main() {

    return 0;
}
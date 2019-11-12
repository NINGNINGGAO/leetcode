/*
 * @Author: AGOGIN
 * @Date: 2019-11-12 15:10:30
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-12 15:21:33
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int caseSensitive(char s) {
    if (s >= 'a' && s <= 'z') return -1;
    else if (s >= 'A' && s <= 'Z') return 1;
    else return 0;
}
bool detectCapitalUse(char * word){
    int p = 0;
    int init = caseSensitive(word[p++]);
    int flag;
    if (init == -1) {
        while (word[p] != '\0') {
            if (caseSensitive(word[p]) == 1) return false;
            p++;
        }
    } else {
        if (word[p] != '\0') flag = caseSensitive(word[p]);
        while (word[p] != '\0') {
            if (caseSensitive(word[p]) != flag) return false;
            p++;
        }
    }
    return true;
}

int main() {

    return 0;
}
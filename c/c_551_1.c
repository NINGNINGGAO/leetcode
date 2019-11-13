/*
 * @Author: AGOGIN
 * @Date: 2019-11-13 17:42:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-13 17:47:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool checkRecord(char * s){
    int flagA = 0;
    int flagL = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'A') {
            flagA++;
            if (flagA > 1) return false;
        } else if (s[i] == 'L' && i > 1) {
            if (s[i - 1] == 'L' && s[i - 2] == 'L') return false;
        }
        i++;
    }
    return true;
}

int main() {

    return 0;
}
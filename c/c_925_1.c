/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 11:00:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 11:10:52
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isLongPressedName(char * name, char * typed){
    int p = 0, q = 0;
    int nLen = strlen(name), tLen = strlen(typed);
    if (name[p++] != typed[q++]) return false;
    while (q < tLen) {
        if (name[p] == typed[q]) {
            p++;
            q++;
        } else {
            if (typed[q] != name[p - 1]) return false;
            else q++;
        }
    }
    if (p == nLen)return true;
    else return false;
}

int main() {

    return 0;
}
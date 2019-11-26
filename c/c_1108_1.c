/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 17:08:23
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 17:11:25
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * defangIPaddr(char * address){
    int sLen = strlen(address);
    char* res = malloc(sizeof(char) * (sLen + 7));
    memset(res, 0, sizeof(char) * (sLen + 7));
    int count = 0;
    for (int i = 0; i < sLen; i++) {
        if (address[i] != '.') {
            res[count++] = address[i];
        } else {
            sprintf(res, "%s[.]", res);
            count += 3;
        }
    }
    return res;
}

int main() {

    return 0;
}
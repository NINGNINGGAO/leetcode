/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 10:37:13
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 10:44:49
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#define ascii 128
int numJewelsInStones(char * J, char * S){
    int* jMap = malloc(sizeof(int) * ascii);
    int* sMap = malloc(sizeof(int) * ascii);
    memset(jMap, 0, sizeof(int) * ascii);
    memset(sMap, 0, sizeof(int) * ascii);
    for (int i = 0; i < strlen(J); i++) {
        jMap[J[i]]++;
    }
    for (int i = 0; i < strlen(S); i++) {
        sMap[S[i]]++;
    }
    int res = 0;
    for (int i = 0; i < ascii; i++) {
        if (jMap[i]) res += sMap[i];
    }
    free(sMap);
    free(jMap);
    return res;
}

int main() {

    return 0;
}
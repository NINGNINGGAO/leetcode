/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 19:46:11
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 20:25:11
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * toGoatLatin(char * S){
    int* flag = malloc(sizeof(int) * 128);
    memset(flag, 0, sizeof(int) * 128);
    flag['a'] = 1;
    flag['e'] = 1;
    flag['i'] = 1;
    flag['o'] = 1;
    flag['u'] = 1;
    flag['A'] = 1;
    flag['E'] = 1;
    flag['I'] = 1;
    flag['O'] = 1;
    flag['U'] = 1;
    char** temp = malloc(sizeof(char*) * 256);
    int count = 0;
    temp[count++] = &(S[0]);
    int sLen = strlen(S);
    for (int i = 1; i < sLen; i++) {
        if (S[i] == ' ') {
            temp[count++] = &(S[i + 1]);
            S[i] = '\0';
        }
    }
    char* res = malloc(sizeof(char) * 2048);
    memset(res, 0, sizeof(char) * 2048);
    for (int i = 0; i < count; i++) {
        if (flag[temp[i][0]] == 0) {
            sprintf(res, "%s%s%c", res, &(temp[i][1]), temp[i][0]);
        } else {
            sprintf(res, "%s%s", res, temp[i]);
        }
        sprintf(res, "%sma", res);
        for (int j = 0; j <= i; j++) {
            sprintf(res, "%sa", res);
        }
        sprintf(res, "%s ", res);
    }
    int resLen = strlen(res);
    res[resLen - 1] = '\0';
    return res;
}

int main() {
    char* S = malloc(sizeof(char) * 100);
    memset(S, 0, sizeof(char) * 100);
    char temp[] = "The quick brown fox jumped over the lazy dog";
    S = strcat(S, temp);
    char* res = toGoatLatin(S);
    printf("%s\n", res);
    return 0;
}
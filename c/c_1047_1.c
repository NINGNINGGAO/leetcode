/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 17:21:29
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 17:50:03
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char * removeDuplicates(char * S){
    int count = 1;
    int sLen = strlen(S);
    for (int i = 1; i < sLen; i++) {
        if (count > 0 && S[count - 1] == S[i]) count--;
        else S[count++] = S[i];
    }
    S[count] = '\0';
    return S;
}

int main() {
    char S[] = "abbaca";
    char* res = removeDuplicates(S);
    printf("%s\n", res);
    return 0;
}
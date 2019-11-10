/*
 * @Author: AGOGIN
 * @Date: 2019-11-10 16:48:56
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-10 17:14:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char upper(char s, int num) {
    return s - 'a' + 'A';
}
void addDash(int* K, int* countNum, char* arr, int* Len) {
    if (*countNum == *K) {
        *countNum = 0;
        arr[(*Len)--] = '-';
    }
}
char * licenseKeyFormatting(char * S, int K){
    int Len = strlen(S) * 2 + 1;
    char* temp = malloc(sizeof(char) * Len);
    temp[--Len] = '\0';
    Len--;
    int countNum = 0;
    for (int i = strlen(S) - 1; i >= 0; i--) {
        if (S[i] == '-') continue;
        else if (S[i] >= 'a' && S[i] <= 'z') temp[Len--] = upper(S[i], i);
        else temp[Len--] = S[i];
        countNum++;
        addDash(&K, &countNum, temp, &Len);
    }
    if (temp[Len + 1] == '-') Len++;
    char* res = malloc(sizeof(char) * (strlen(S) * 2 + 1 - Len));
    res[0] = '\0';
    res = strcpy(res, temp + Len + 1);
    return res;
}

int main() {

    return 0;
}
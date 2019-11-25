/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 09:45:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 09:57:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}
char * gcdOfStrings(char * str1, char * str2){
    int aLen = strlen(str1), bLen = strlen(str2);
    char* temp1 = malloc(sizeof(char) * (aLen + bLen + 1));
    memset(temp1, 0, sizeof(char) * (aLen + bLen + 1));
    char* temp2 = malloc(sizeof(char) * (aLen + bLen + 1));
    memset(temp2, 0, sizeof(char) * (aLen + bLen + 1));
    sprintf(temp1, "%s%s", str1, str2);
    sprintf(temp2, "%s%s", str2, str1);
    if (strcmp(temp1, temp2) != 0) return "";
    free(temp1);
    free(temp2);
    int cLen = gcd(aLen, bLen);
    char* res = malloc(sizeof(char) * (aLen + 1));
    memset(res, 0, sizeof(char) * (aLen + 1));
    sprintf(res, "%s", str1);
    res[cLen] = '\0';
    return res;
}

int main() {

    return 0;
}
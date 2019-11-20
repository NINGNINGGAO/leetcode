/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 11:29:00
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 11:34:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
typedef char Element;
int* computePrefix(Element* s, int sSize) {
    int* res = malloc(sizeof(int) * sSize);
    res[0] = 0;
    int k = 0;
    for (int i = 1; i < sSize; i++) {
        while (k > 0 && s[i] != s[k]) k = res[k - 1];
        if (s[i] == s[k]) k++;
        res[i] = k;
    }
    return res;
}
bool rotateString(char * A, char * B){
    int aLen = strlen(A), bLen = strlen(B);
    if (aLen != bLen) return false;
    if (aLen == 0) return true;
    int n = aLen * 2 + 1;
    char* C = malloc(sizeof(char) * n);
    memset(C, 0, sizeof(char) * n);
    sprintf(C, "%s%s%s", C, A, A);
    int* arr = computePrefix(B, bLen);
    int i, j = 0, flag = 0;
    for (i = 0; i < n; i++) {
        while (j > 0 && B[j] != C[i]) j = arr[j - 1];
        if (B[j] == C[i]) j++;
        if (j == bLen) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) return true;
    else return false;
}

int main() {

    return 0;
}
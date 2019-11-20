/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 15:08:52
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 15:49:30
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(char* S, int sLen, char** res, int* returnSize, int index) {
    if (S[index] == '\0') {
        res[*returnSize] = malloc(sizeof(char) * (sLen + 1));
        memset(res[*returnSize], 0, sizeof(char) * (sLen + 1));
        sprintf(res[*returnSize], "%s", S);
        (*returnSize)++;
    } else {
        if (isalpha(S[index])) {
            char temp = S[index] ^ (1 << 5);
            dfs(S, sLen, res, returnSize, index + 1);
            S[index] = temp;
            dfs(S, sLen, res, returnSize, index + 1);
            index++;
        } else {
            index++;
            dfs(S, sLen, res, returnSize, index);
        }
    }
}
char ** letterCasePermutation(char * S, int* returnSize){
    *returnSize = 0;
    int sLen = strlen(S);
    if (sLen == 0) return NULL;
    char** res = malloc(sizeof(char*) * 6000);
    memset(res, 0, sizeof(char*) * 6000);
    int index = 0;
    dfs(S, sLen, res, returnSize, index);
    return res;
}

int main() {
    char S[] = "a1b2";
    int num;
    char** res = letterCasePermutation(S, &num);
    for (int i = 0; i < num; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 22:54:25
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-26 10:10:12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int minFre(char* s) {
    int temp[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        temp[s[i] - 'a']++;
    }
    int res;
    for (int i = 0; i < 26; i++) {
        if (temp[i] != 0) {
            res = temp[i];
            break;
        }
    }
    return res;
}
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize){
    *returnSize = queriesSize;
    int* qF = malloc(sizeof(int) * queriesSize);
    int* wF = malloc(sizeof(int) * wordsSize);
    int* res = malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        qF[i] = minFre(queries[i]);
    }
    for (int i = 0; i < wordsSize; i++) {
        wF[i] = minFre(words[i]);
    }
    qsort(wF, wordsSize, sizeof(int), cmp);
    int flag;
    for (int i = 0; i < queriesSize; i++) {
        int j;
        flag = 0;
        for (j = 0; j < wordsSize; j++) {
            if (wF[j] > qF[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) res[i] = wordsSize - j;
        else res[i] = 0;
    }
    return res;
}

int main() {

    return 0;
}
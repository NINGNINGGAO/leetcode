/*
 * @Author: AGOGIN
 * @Date: 2019-11-19 20:52:25
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 21:26:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#define alphabet 26
char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    char* res = NULL;
    int minLen = INT_MAX;
    int* arr = malloc(sizeof(int) * alphabet);
    memset(arr, 0, sizeof(int) * alphabet);
    int mid = 0, wordsLen;
    for (int i = 0; i < strlen(licensePlate); i++) {
        if (isalpha(licensePlate[i])) arr[tolower(licensePlate[i]) - 'a']++;
    }
    int* flag = malloc(sizeof(int) * alphabet);
    for (int i = 0; i < wordsSize; i++) {
        mid = 0;
        wordsLen = strlen(words[i]);
        memset(flag, 0, sizeof(int) * alphabet);
        for (int j = 0; j < wordsLen; j++) {
            if (isalpha(words[i][j])) flag[tolower(words[i][j]) - 'a']++;
        }
        for (int k = 0; k < alphabet; k++) {
            if (flag[k] < arr[k]) {
                mid = 1;
                break;
            }
        }
        if (mid == 0 && wordsLen < minLen) {
            res = words[i];
            minLen = wordsLen;
        }
    }
    free(flag);
    free(arr);
    return res;
}

int main() {
    char licensePlate[] = "1s3 PSt";
    int wordsSize = 4;
    char** words = malloc(sizeof(char*) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        words[i] = malloc(sizeof(char) * 20);
        memset(words[i], 0, sizeof(char) * 20);
    }
    words[0] = "step";
    words[1] = "steps";
    words[2] = "stripe";
    words[3] = "stepple";
    char* res = shortestCompletingWord(licensePlate, words, wordsSize);
    return 0;
}
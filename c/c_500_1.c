/*
 * @Author: AGOGIN
 * @Date: 2019-11-11 09:39:00
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-11 10:03:27
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int autoi(char s) {
    if (s >= 'A' && s<= 'Z') return s - 'A';
    return s - 'a';
}
char ** findWords(char ** words, int wordsSize, int* returnSize){
    *returnSize = 0;
    if (wordsSize == 0) return NULL;
    int hashMap[] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
    int temp, flag;
    char** res = malloc(sizeof(char*) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        int j = 1, flag = 0;
        temp = hashMap[autoi(words[i][0])];
        while (words[i][j] != '\0') {
            if (hashMap[autoi(words[i][j])] != temp) {
                flag = 1;
                break;
            }
            j++;
        }
        if (flag != 1) {
            res[*returnSize] = malloc(sizeof(char) * (j + 1));
            res[*returnSize][0] = '\0';
            res[*returnSize] = strcpy(res[*returnSize], words[i]);
            (*returnSize)++;
        }
    }
    return res;
}

int main() {
    char** s = malloc(sizeof(char*) * 4);
    s[0] = "Hello";
    s[1] = "Alaska";
    s[2] = "Dad";
    s[3] = "Peace";
    int num;
    char** res = findWords(s, 4, &num);
    return 0;
}
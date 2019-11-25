/*
 * @Author: AGOGIN
 * @Date: 2019-11-25 09:59:14
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-25 10:14:36
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
    *returnSize = 0;
    char** res = malloc(sizeof(char*) * 512);
    char** temp = malloc(sizeof(char*) * 512);
    int count = 0;
    temp[count++] = &(text[0]);
    int tLen = strlen(text);
    for (int i = 1; i < tLen; i++) {
        if (text[i] == ' ') {
            text[i] = '\0';
            temp[count++] = &(text[i + 1]);
        }
    }
    int i = 0;
    while (i < count) {
        if (strcmp(temp[i], first) == 0) {
            i++;
            if (i < count && strcmp(temp[i], second) == 0) {
                i++;
                if (i < count) res[(*returnSize)++] = temp[i];
            }
        } else {
            i++;
        }
    }
    return res;
}

int main() {
    char text[] = "we will we will rock you";
    char f[] = "we";
    char s[] = "will";
    int n;
    char** res = findOcurrences(text, f, s, &n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}
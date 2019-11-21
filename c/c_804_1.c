/*
 * @Author: AGOGIN
 * @Date: 2019-11-20 21:29:57
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-20 22:00:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}
int uniqueMorseRepresentations(char ** words, int wordsSize){
    if (wordsSize == 0) return 0;
    char mobMap[26][6] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char** arr = malloc(sizeof(char*) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        arr[i] = malloc(sizeof(char) * 81);
        memset(arr[i], 0, sizeof(char) * 81);
        for (int j = 0; j < strlen(words[i]); j++) {
            arr[i] = strcat(arr[i], mobMap[words[i][j] - 'a']);
        }
    }
    qsort(arr, wordsSize, sizeof(char*), cmp);
    char* temp = arr[0];
    int res = 1;
    for (int i = 1; i < wordsSize; i++) {
        if (strcmp(temp, arr[i]) != 0) {
            res++;
            temp = arr[i];
        }
    }
    return res;
}

int main() {
    int a[][2] = {{1,2},{3,4}};

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 10:12:57
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-24 10:36:50
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define Min(a, b) ((a) < (b) ? (a) : (b))
char ** commonChars(char ** A, int ASize, int* returnSize){
    int** temp = malloc(sizeof(int*) * ASize);
    for (int i = 0; i < ASize; i++) {
        temp[i] = malloc(sizeof(int) * 26);
        memset(temp[i], 0, sizeof(int) * 26);
        for (int j = 0; j < strlen(A[i]); j++) {
            temp[i][A[i][j] - 'a']++;
        }
    }
    char** res = malloc(sizeof(char*) * 100);
    *returnSize = 0;
    int* arr = malloc(sizeof(int) * 26);
    for (int i = 0; i < 26; i++) {
        arr[i] = temp[0][i];
        for (int j = 1; j < ASize; j++) {
            arr[i] = Min(arr[i], temp[j][i]);
        }
        for (int k = 0; k < arr[i]; k++) {
            res[*returnSize] = malloc(sizeof(char) * 2);
            memset(res[*returnSize], 0, sizeof(char) * 2);
            sprintf(res[*returnSize], "%c", (char)(i + 'a'));
            (*returnSize)++;
        }
    }
    return res;
}

int main() {
    char a[][10] = {"bella","label","broller"};
    int AS = 3;
    char** s = malloc(sizeof(char*) * AS);
    for (int i = 0; i < AS; i++) {
        s[i] = a[i];
    }
    int n;
    char** res = commonChars(s, AS, &n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}
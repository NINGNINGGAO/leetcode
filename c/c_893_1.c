/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 20:56:52
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 21:24:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node {
    char odd[12];
    char even[12];
};
int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}
int cmpStr(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}
int numSpecialEquivGroups(char ** A, int ASize){
    if (ASize < 2) return ASize;
    struct Node* arr = malloc(sizeof(struct Node));
    char** temp = malloc(sizeof(char*) * ASize);
    int i, j;
    for (i = 0; i < ASize; i++) {
        memset(arr, 0, sizeof(struct Node));
        for (j = 0; j < strlen(A[i]); j++) {
            if (j % 2 == 0) arr->even[j / 2] = A[i][j];
            else arr->odd[j / 2] = A[i][j];
        }
        qsort(arr->odd, strlen(arr->odd), sizeof(char), cmp);
        qsort(arr->even, strlen(arr->even), sizeof(char), cmp);
        temp[i] = malloc(sizeof(char) * (strlen(A[i]) + 1));
        memset(temp[i], 0, sizeof(char) * (strlen(A[i]) + 1));
        sprintf(temp[i], "%s%s", arr->odd, arr->even);
    }
    free(arr);
    qsort(temp, ASize, sizeof(char*), cmpStr);
    int res = 1;
    for (int i = 1; i < ASize; i++) {
        if (strcmp(temp[i], temp[i - 1])) res++;
    }
    return res;
}

int main() {

    return 0;
}
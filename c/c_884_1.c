/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 15:28:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 15:44:52
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}
char ** uncommonFromSentences(char * A, char * B, int* returnSize){
    int aLen = strlen(A), bLen = strlen(B);
    char** mid = malloc(sizeof(char*) * 512);
    int count = 0;
    mid[count++] = &(A[0]);
    for (int i = 1; i < aLen - 1; i++) {
        if (A[i] == ' ') {
            A[i] = '\0';
            mid[count++] = &(A[i + 1]);
        }
    }
    mid[count++] = &(B[0]);
    for (int i = 1; i < bLen - 1; i++) {
        if (B[i] == ' ') {
            B[i] = '\0';
            mid[count++] = &(B[i + 1]);
        }
    }
    qsort(mid, count, sizeof(char*), cmp);
    *returnSize = 0;
    char** res = malloc(sizeof(char*) * 512);
    char* temp = mid[0];
    int num = 1;
    for (int i = 1; i < count; i++) {
        if (strcmp(temp, mid[i]) == 0) num++;
        else {
            if (num == 1) res[(*returnSize)++] = temp;
            temp = mid[i];
            num = 1;
        }
    }
    if (num == 1) res[(*returnSize)++] = temp;
    return res;
}

int main() {
    char A[] = "apple apple";
    char B[] = "banana";
    int num;
    char** res = uncommonFromSentences(A, B, &num);
    for (int i = 0; i < num; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}
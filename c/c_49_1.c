/*
 * @Author: AGOGIN
 * @Date: 2019-11-30 19:00:37
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-30 19:44:18
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct Node {
    char* str;
    int sLen;
    int flag[26];
};
int strCmp(int* a, int* b) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return a[i] - b[i];
    }
    return 0;
}
int cmp(const void* a, const void* b) {
    int aLen = ((struct Node*)a)->sLen, bLen = ((struct Node*)b)->sLen;
    if (aLen != bLen) return aLen - bLen;
    else return strCmp(((struct Node*)a)->flag, ((struct Node*)b)->flag);
}
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * strsSize);
    memset(*returnColumnSizes, 0, sizeof(int) * strsSize);
    if (strsSize == 0) return NULL;
    char*** res = malloc(sizeof(char**) * strsSize);
    struct Node* arr = malloc(sizeof(struct Node) * strsSize);
    memset(arr, 0, sizeof(struct Node) * strsSize);
    for (int i = 0; i < strsSize; i++) {
        arr[i].str = strs[i];
        arr[i].sLen = strlen(strs[i]);
        for (int j = 0; j < (arr[i].sLen); j++) {
            (arr[i].flag[strs[i][j] - 'a'])++;
        }
    }
    qsort(arr, strsSize, sizeof(struct Node), cmp);
    res[*returnSize] = malloc(sizeof(char*) * 1024);
    res[*returnSize][(*returnColumnSizes)[*returnSize]] = arr[0].str;
    ((*returnColumnSizes)[*returnSize])++;
    for (int i = 1; i < strsSize; i++) {
        if (cmp(&(arr[i]), &(arr[i - 1]))) {
            (*returnSize)++;
            res[*returnSize] = malloc(sizeof(char*) * strsSize);
        }
        res[*returnSize][(*returnColumnSizes)[*returnSize]] = arr[i].str;
        ((*returnColumnSizes)[*returnSize])++;
    }
    (*returnSize)++;
    free(arr);
    return res;
}

int main() {
    char temp[][10] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = 6;
    int p, *q;
    char** strs = malloc(sizeof(char*) * 6);
    for (int i = 0; i < n; i++) {
        strs[i] = temp[i];
    }
    char*** res = groupAnagrams(strs, n, &p, &q);
    return 0;
}
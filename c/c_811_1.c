/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 09:53:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 11:10:03
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Node {
    int val;
    char* str;
};
int cmp(const void* a, const void* b) {
    return strcmp((*(struct Node**)a)->str, (*(struct Node**)b)->str);
}
char ** subdomainVisits(char ** cpdomains, int cpdomainsSize, int* returnSize){
    *returnSize = 0;
    if (cpdomainsSize == 0) return NULL;
    struct Node** arr = malloc(sizeof(struct Node*) * 3 * cpdomainsSize);
    int mid = 0;
    int arrSize = 0;
    int flag = 0;
    for (int i = 0; i < cpdomainsSize; i++) {
        flag = 0;
        for (int j = 0; j < strlen(cpdomains[i]); j++) {
            if (flag == 0 && cpdomains[i][j] == ' ') {
                cpdomains[i][j] = '\0';
                mid = atoi(cpdomains[i]);
                cpdomains[i][j] = ' ';
                flag = 1;
            }
            if ((flag == 1) && (cpdomains[i][j] == '.' || cpdomains[i][j] == ' ')) {
                arr[arrSize] = malloc(sizeof(struct Node));
                arr[arrSize]->val = mid;
                arr[arrSize]->str = &(cpdomains[i][j + 1]);
                arrSize++;
            }
        }
    }
    char** res = malloc(sizeof(char*) * arrSize);
    qsort(arr, arrSize, sizeof(struct Node*), cmp);
    struct Node* temp = arr[0];
    int count = temp->val;
    for (int i = 1; i < arrSize; i++) {
        if (strcmp(temp->str, arr[i]->str) != 0) {
            res[*returnSize] = malloc(sizeof(char) * 150);
            memset(res[*returnSize], 0, sizeof(char) * 150);
            sprintf(res[*returnSize], "%d %s", count, temp->str);
            (*returnSize)++;
            temp = arr[i];
            count = temp->val;
        } else {
            count += arr[i]->val;
        }
    }
    res[*returnSize] = malloc(sizeof(char) * 150);
    memset(res[*returnSize], 0, sizeof(char) * 150);
    sprintf(res[*returnSize], "%d %s", count, temp->str);
    (*returnSize)++;
    return res;
}

int main() {
    int sLen = 1;
    char** s = malloc(sizeof(char*) * sLen);
    s[0] = malloc(sizeof(char) * 100);
    memset(s[0], 0, sizeof(char) * 100);
    char temp[] = "9001 discuss.leetcode.com";
    s[0] = strcat(s[0], temp);
    int num;
    char** res = subdomainVisits(s, sLen, &num);
    for (int i = 0; i < num; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}
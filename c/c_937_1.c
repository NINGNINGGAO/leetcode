/*
 * @Author: AGOGIN
 * @Date: 2019-11-23 14:03:54
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-23 17:06:29
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
    char *str;
};
int cmp(const void* a, const void* b) {
    if (((struct Node*)a)->val == 0 && ((struct Node*)b)->val == 0) return -1;
    else if (((struct Node*)a)->val == 0) return 1;
    else if (((struct Node*)b)->val == 0) return -1;
    else {
        int temp = strcmp(&(((struct Node*)a)->str[((struct Node*)a)->val]), &(((struct Node*)b)->str[((struct Node*)b)->val]));
        if (temp != 0) return temp;
        else return strcmp(((struct Node*)a)->str, ((struct Node*)b)->str);
    }
}
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    *returnSize = logsSize;
    if (logsSize <= 1) return logs;
    struct Node* temp = malloc(sizeof(struct Node) * logsSize);
    memset(temp, 0, sizeof(struct Node) * logsSize);
    for (int i = 0; i < logsSize; i++) {
        temp[i].str = logs[i];
        for (int j = 0; j < strlen(logs[i]); j++) {
            if (logs[i][j] == ' ') {
                if (isalpha(logs[i][j + 1])) temp[i].val = j + 1;
                break;
            }
        }
    }
    qsort(temp, logsSize, sizeof(struct Node), cmp);
    char** res = malloc(sizeof(char*) * logsSize);
    for (int i = 0; i < logsSize; i++) {
        res[i] = temp[i].str;
    }
    return res;
}

int main() {
    char temp[][100] = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"};
    int num = sizeof(temp) / (sizeof(char) * 100);
    char** s = malloc(sizeof(char*) * num);
    for (int i = 0; i < num; i++) {
        s[i] = temp[i];
    }
    int n;
    char** res = reorderLogFiles(s, num, &n);
    for (int i = 0; i < num; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}
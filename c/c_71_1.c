/*
 * @Author: AGOGIN
 * @Date: 2019-12-03 15:05:14
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-03 22:19:08
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node {
    char** arr;
    int rear;
};
struct Node* creatStack(int cap) {
    struct Node* S = malloc(sizeof(struct Node));
    S->arr = malloc(sizeof(char*) * cap);
    S->rear = 0;
    return S;
}
void pushStack(struct Node* S, char* str) {
    if (str[0] != '.' || strlen(str) > 2) {
        S->arr[(S->rear)++] = str;
    } else if (str[0] == '.' && strlen(str) == 2 && S->rear > 0) {
        (S->rear)--;
    }
}
void freeStack(struct Node* S) {
    free(S->arr);
    free(S);
}
char * simplifyPath(char * path){
    int sLen = strlen(path);
    if (sLen <= 1) return "/";
    for (int i = 0; i < sLen; i++) {
        if (path[i] == '/') path[i] = '\0';
    }
    int cap = 1024;
    struct Node* S = creatStack(cap);
    for (int i = 1; i < sLen; i++) {
        if (path[i - 1] == '\0' && path[i] != '\0') {
            pushStack(S, &(path[i]));
        }
    }
    char* res = malloc(sizeof(char) * (sLen + 1));
    memset(res, 0, sizeof(char) * (sLen + 1));
    for (int i = 0; i < S->rear; i++) {
        sprintf(res, "%s/%s", res, S->arr[i]);
    }
    if (S->rear <= 0) res[0] = '/';
    freeStack(S);
    return res;
}

int main() {
    char s[] = "/...";
    char* res = simplifyPath(s);
    printf("%s\n", res);
    return 0;
}
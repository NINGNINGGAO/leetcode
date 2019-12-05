/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 12:04:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-05 15:15:05
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void numsToStr(char** res, int* returnSize, long long* flag, int count) {
    res[*returnSize] = malloc(sizeof(char) * 16);
    memset(res[*returnSize], 0, sizeof(char) * 16);
    sprintf(res[*returnSize], "%d", flag[0]);
    for (int i = 1; i < count; i++) {
        sprintf(res[*returnSize], "%s.%d", res[*returnSize], flag[i]);
    }
    (*returnSize)++;
}
long long strToNum(char* s, int begin, int end) {
    long long res = 0;
    for (int i = begin; i <= end; i++) {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}
void backTrack(char* s, int point, char** res, int* returnSize, long long* flag, int count) {
    if (count == 4) numsToStr(res, returnSize, flag, count);
    else {
        if (count < 3) {
            for (int i = point; i < strlen(s) - 3 + count; i++) {
                flag[count] = strToNum(s, point, i);
                if (flag[count] > 255 || (i - point != 0 && flag[count] < 10)) break;
                else backTrack(s, i + 1, res, returnSize, flag, count + 1);
            }
        } else if (count == 3){
            flag[count] = strToNum(s, point, strlen(s) - 1);
            long long temp = pow(10, strlen(s) - 1 - point);
            if (!(flag[count] > 255 || (strlen(s) - 1 - point != 0 && flag[count] < temp))) backTrack(s, strlen(s), res, returnSize, flag, count + 1);
        }
    }
}
char ** restoreIpAddresses(char * s, int* returnSize){
    *returnSize = 0;
    if (strlen(s) < 4 || strlen(s) > 12) return NULL;
    char** res = malloc(sizeof(char*) * 100);
    long long* flag = malloc(sizeof(long long) * 4);
    int count = 0;
    int point = 0;
    backTrack(s, point, res, returnSize, flag, count);
    return res;
}

int main() {
    char s[] = "010010";
    int n;
    char** res = restoreIpAddresses(s, &n);
    return 0;
}
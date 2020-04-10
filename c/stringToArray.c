/*
 * @Author: AGOGIN 
 * @Date: 2020-03-20 23:43:40 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-29 15:37:42
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#define maxNum 1024

int** stringToArray(char* s, int* returnSize, int** returnColumnSizes) {
    int sLen = strlen(s);
    *returnSize = 0;
    if (sLen <= 2) return NULL;
    *returnColumnSizes = malloc(sizeof(int) * maxNum);
    memset(*returnColumnSizes, 0, sizeof(int) * maxNum);
    int** ret = malloc(sizeof(int*) * maxNum);
    for (int i = 1; i < sLen - 1; i++) {
        if (s[i - 1] == '[' && isdigit(s[i])) {
            ret[*returnSize] = malloc(sizeof(int) * maxNum);
            memset(ret[*returnSize], 0, sizeof(int) * maxNum);
            ret[*returnSize][(*returnColumnSizes)[*returnSize]] = s[i] - '0';
        } else if (isdigit(s[i])) {
            ret[*returnSize][(*returnColumnSizes)[*returnSize]] = \
            ret[*returnSize][(*returnColumnSizes)[*returnSize]] * 10 + (s[i] - '0');
        } else if (isdigit(s[i - 1]) && s[i] == ',') {
            (*returnColumnSizes)[*returnSize]++;
        } else if (s[i] == ']') {
            (*returnColumnSizes)[*returnSize]++;
            (*returnSize)++;
        }
    }
    return ret;
}


int main() {
    char* s = malloc(sizeof(char) * 1024);
    scanf("%s", s);
    //char s[] = "[[2],[3,4],[6,5,7],[4,1,8,3]]";
    int numsSize = 0;
    int* numsColumnSizes;
    int** nums = stringToArray(s, &numsSize, &numsColumnSizes);
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColumnSizes[i]; j++) {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
    return 0;
}
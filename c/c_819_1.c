/*
 * @Author: AGOGIN
 * @Date: 2019-11-21 14:59:09
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-21 20:25:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node {
    int val;
    char* str;
};
int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}
char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
    int sLen = strlen(paragraph);
    char** temp = malloc(sizeof(char*) * 1024);
    int count = 0;
    temp[count++] = &(paragraph[0]);
    for (int i = 0; i < sLen; i++) {
        if (isupper(paragraph[i])) paragraph[i] ^= (1 << 5);
        else if (!isalpha(paragraph[i])) paragraph[i] = '\0';
        if (i > 0 && isalpha(paragraph[i]) && !isalpha(paragraph[i - 1])) temp[count++] = &(paragraph[i]);
    }
    qsort(temp, count, sizeof(char*), cmp);
    struct Node** mid = malloc(sizeof(struct Node*) * count);
    int midSize = 0;
    char* tmp = temp[0];
    int tSize = 1;
    for (int i = 1; i < count; i++) {
        if (strcmp(tmp, temp[i]) == 0) tSize++;
        else {
            mid[midSize] = malloc(sizeof(struct Node));
            mid[midSize]->str = tmp;
            mid[midSize]->val = tSize;
            midSize++;
            tSize = 1;
            tmp = temp[i];
        }
    }
    mid[midSize] = malloc(sizeof(struct Node));
    mid[midSize]->str = tmp;
    mid[midSize]->val = tSize;
    midSize++;
    int maxNum = 0;
    char* res;
    int flag = 0;
    for (int i = 0; i < midSize; i++) {
        flag = 0;
        if (mid[i]->val > maxNum) {
            for (int j = 0; j < bannedSize; j++) {
                if (strcmp(mid[i]->str, banned[j]) == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag != 1) {
                maxNum = mid[i]->val;
                res = mid[i]->str;
            }
        }
    }
    return res;
}

int main() {
    char* paragraph = malloc(sizeof(char) * 50);
    memset(paragraph, 0, sizeof(char) * 50);
    char temp[] = "a\na\na\na\nb,b,b,c\nc";
    paragraph = strcat(paragraph, temp);
    int num = 1;
    char** ban = malloc(sizeof(char*) * num);
    ban[0] = malloc(sizeof(char) * 10);
    memset(ban[0], 0, sizeof(char) * 10);
    char tmp[] = "a";
    ban[0] = strcat(ban[0], tmp);
    char* res = mostCommonWord(paragraph, ban, num);
    printf("%s\n", res);
    return 0;
}
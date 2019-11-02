/*
 * @Author: AGOGIN
 * @Date: 2019-11-02 17:30:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-02 18:31:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Letter 26
#define sLen 128
bool wordPattern(char * pattern, char * str){
    char** hash = malloc(sizeof(char*) * Letter);
    for (int i = 0; i < Letter; i++) {
        hash[i] = malloc(sizeof(char) * sLen);
        memset(hash[i], 0, sizeof(char) * sLen);
        hash[i][0] = '\0';
    }
    int i = 0, j;
    char* temp = malloc(sizeof(char) * sLen);
    while (pattern[i] != '\0') {
        j = 0;
        if (*str == '\0') return false;
        while (*str != ' ' && *str != '\0') {
            temp[j++] = *str;
            str++;
        }
        temp[j] = '\0';
        if (*str == ' ') str++;
        if (strlen(hash[pattern[i] - 'a']) == 0) {
            for (int k = 0; k < Letter; k++) {
                if (k != pattern[i] - 'a' && strlen(hash[k]) > 0) {
                    if (strcmp(hash[k], temp) == 0) return false;
                }
            }
            strcpy(hash[pattern[i] - 'a'], temp);
        } else {
            if (strcmp(hash[pattern[i] - 'a'], temp) != 0) return false;
        }
        i++;
    }
    if (strlen(str) != 0) return false;
    return true;
}

int main() {
    char* pattern = "jquery";
    char* str = "jquery";
    bool res =wordPattern(pattern, str);
    printf("%d\n", res);
    return 0;
}
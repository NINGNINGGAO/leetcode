/*
 * @Author: AGOGIN
 * @Date: 2019-11-04 16:19:22
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-04 16:24:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Alphabet 26
void hashMap(char* s, int* res) {
    int i = 0;
    while (s[i] != '\0') {
        res[s[i++] - 'a']++;
    }
}
char findTheDifference(char * s, char * t){
    if (strlen(s) == 0) return *t;
    int* res1 = malloc(sizeof(int) * Alphabet);
    int* res2 = malloc(sizeof(int) * Alphabet);
    memset(res1, 0, sizeof(int) * Alphabet);
    memset(res2, 0, sizeof(int) * Alphabet);
    hashMap(s, res1);
    hashMap(t, res2);
    char res;
    for (int i = 0; i < Alphabet; i++) {
        if (res1[i] != res2[i]) res = i + 'a';
    }
    return res;
}

int main() {

    return 0;
}
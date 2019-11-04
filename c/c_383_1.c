/*
 * @Author: AGOGIN
 * @Date: 2019-11-04 15:47:38
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-04 16:14:27
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
bool canConstruct(char * ransomNote, char * magazine){
    if (strlen(ransomNote) == 0) return true;
    if (strlen(magazine) == 0) return false;
    int* res1 = malloc(sizeof(int) * Alphabet);
    int* res2 = malloc(sizeof(int) * Alphabet);
    memset(res1, 0, sizeof(int) * Alphabet);
    memset(res2, 0, sizeof(int) * Alphabet);
    hashMap(ransomNote, res1);
    hashMap(magazine, res2);
    for (int i = 0; i < Alphabet; i++) {
        if (res1[i] > res2[i]) return false;
    }
    return true;
}

int main() {

    return 0;
}



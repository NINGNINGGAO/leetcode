/*
 * @Author: AGOGIN
 * @Date: 2019-11-04 16:14:31
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-04 16:18:39
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
int firstUniqChar(char * s){
    if (strlen(s) == 0) return -1;
    int* hash = malloc(sizeof(int) * Alphabet);
    memset(hash, 0, sizeof(int) * Alphabet);
    hashMap(s, hash);
    int res = 0;
    while (s[res] != '\0') {
        if (hash[s[res] - 'a'] == 1) return res;
        res++;
    }
    return -1;
}

int main() {

    return 0;
}
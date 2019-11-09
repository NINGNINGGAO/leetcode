/*
 * @Author: AGOGIN
 * @Date: 2019-11-09 10:43:19
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-09 12:03:57
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
typedef char Element;
int* computePrefix(Element* s, int sSize) {
    int* res = malloc(sizeof(int) * sSize);
    res[0] = 0;
    int k = 0;
    for (int i = 1; i < sSize; i++) {
        while (k > 0 && s[i] != s[k]) k = res[k - 1];
        if (s[i] == s[k]) k++;
        res[i] = k;
    }
    return res;
}
bool repeatedSubstringPattern(char * s){
    int sSize = strlen(s);
    int* res = computePrefix(s, sSize);
    if (res[sSize -1] != 0 && sSize % (sSize - res[sSize - 1]) == 0) return true;
    return false;
}

int main() {
    char s[] = "abab";
    int numsSize = strlen(s);
    bool res = repeatedSubstringPattern(s);
    return 0;
}
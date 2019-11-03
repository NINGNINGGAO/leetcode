/*
 * @Author: AGOGIN
 * @Date: 2019-11-03 10:57:40
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-03 11:30:28
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isBowel(char s) {
    if (s != 'a' && s != 'e' && s != 'i' && s != 'o' && s != 'u' && s != 'A' && s != 'E' && s != 'I' && s != 'O' && s != 'U') return false;
    return true;
}
char * reverseVowels(char * s){
    int sSize = strlen(s);
    if (sSize == 0) return "";
    char* p = malloc(sizeof(char) * (sSize + 1));
    p =strcpy(p, s);
    int slow = 0, fast = sSize - 1;
    char temp;
    while (slow < sSize && isBowel(p[slow]) == false) {
        slow++;
    }
    while (fast > 0 && isBowel(p[fast]) == false) {
        fast--;
    }
    while (slow < fast) {
        temp = p[slow];
        p[slow++] = p[fast];
        p[fast--] = temp;
        while (slow < sSize && isBowel(p[slow]) == false) {
            slow++;
        }
        while (fast >= 0 && isBowel(p[fast]) == false) {
            fast--;
        }
    }
    return p;
}

int main() {
    char* s = " ";
    char* res = reverseVowels(s);
    printf("%s\n", res);
    return 0;
}
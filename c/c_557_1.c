/*
 * @Author: AGOGIN
 * @Date: 2019-11-14 09:09:55
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-14 09:32:44
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void reverseOneWord(char* s, int fast, int last) {
    while (fast < last) {
        s[fast] ^= s[last];
        s[last] ^= s[fast];
        s[fast++] ^= s[last--];
    }
}
char * reverseWords(char * s){
    int fast = 0, last = 0;
    char* res = malloc(sizeof(char) * (strlen(s) + 5));
    memset(res, 0, sizeof(char) * (strlen(s) + 5));
    res = strcpy(res, s);
    while (res[fast] != '\0') {
        if (res[fast] == ' ') fast++;
        else {
            while (res[last] != '\0' && res[last] != ' ') last++;
            reverseOneWord(res, fast, last - 1);
            fast = last + 1;
            last = fast;
        }
    }
    return res;
}

int main() {
    char s[] = "Let's take LeetCode contest";
    char* res = reverseWords(s);
    printf("%s\n", res);
    return 0;
}
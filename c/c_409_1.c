/*
 * @Author: AGOGIN
 * @Date: 2019-11-05 10:21:57
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-05 11:14:36
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define ASICC_LEN 128
int longestPalindrome(char * s){
    int sNum = strlen(s);
    int res = 0;
    if (sNum == 0) return res;
    int* map = malloc(sizeof(int) * ASICC_LEN);
    memset(map, 0, sizeof(int) * ASICC_LEN);
    int i = 0;
    while (s[i] != '\0') {
        map[s[i]]++;
        i++;
    }
    for (int j = 0; j < ASICC_LEN; j++) {
        res += map[j] / 2 * 2;
    }
    if (sNum - res != 0) res++;
    return res;
}

int main() {
    char s[] = "abccccdd";
    int res = longestPalindrome(s);
    return 0;
}
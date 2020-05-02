/*
 * @Author: AGOGIN 
 * @Date: 2020-05-02 10:45:52 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-05-02 11:32:10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char * s){
    int sLen = strlen(s);
    if (sLen <= 1) return sLen;
    int ret = 0;
    int fast = 0, last = 0;
    int *arr = malloc(sizeof(int) * 128);
    memset(arr, 0, sizeof(int) * 128);
    while (fast < sLen) {
        if (arr[s[fast]] == 0) {
            ret = max(ret, fast - last + 1);
            arr[s[fast]]++;
            fast++;
        } else {
            while (s[last] != s[fast]) {
                arr[s[last]]--;
                last++;
            }
            last++;
            fast++;
        }
    }
    free(arr);
    return ret;
}

int main() {
    char s[] = "pwwkew";
    int ret = lengthOfLongestSubstring(s);
    printf("%d\n", ret);
    return 0;
}
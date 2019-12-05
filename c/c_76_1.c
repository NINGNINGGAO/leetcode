/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 15:25:34
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-12-05 15:25:34
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char* copyStr(char* s, int* flag) {
    char* res = malloc(sizeof(char) * (flag[1] - flag[0] + 2));
    memset(res, 0, sizeof(char) * (flag[1] - flag[0] + 2));
    for (int i = flag[0]; i<= flag[1]; i++) {
        res[i - flag[0]] = s[i];
    }
    return res;
}
bool isCover(int* nums1, int* nums2) {
    for (int i = 0; i < 128; i++) {
        if (nums1[i] < nums2[i]) return false;
    }
    return true;
}
char * minWindow(char * s, char * t){
    int sLen = strlen(s), tLen = strlen(t);
    int left = 0, right = 0;
    int flag[2] = {0};
    flag[1] = INT_MAX;
    int tMap[128] = {0};
    for (int i = 0; i < tLen; i++) {
        tMap[t[i]]++;
    }
    int sMap[128] = {0};
    while (right < sLen) {
        sMap[s[right]]++;
        bool temp = isCover(sMap, tMap);
        while (temp == true) {
            if (flag[1] - flag[0] > right - left) {
                flag[0] = left;
                flag[1] = right;
            }
            sMap[s[left]]--;
            left++;
            temp = isCover(sMap, tMap);
        }
        right++;
    }
    if (flag[1] == INT_MAX) return "";
    else return copyStr(s, flag);
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-22 09:46:14
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-22 10:01:53
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool buddyStrings(char * A, char * B){
    int aLen = strlen(A), bLen = strlen(B);
    if (aLen != bLen) return false;
    if (aLen == 0) return true;
    int count = 0;
    int res[3];
    int map[26] = {0};
    for (int i = 0; i < aLen; i++) {
        if (A[i] != B[i]) {
            res[count++] = i;
            if (count > 2) return false;
        } else {
            map[A[i] - 'a']++;
        }
    }
    if (count == 0){
        for (int i = 0; i < 26; i++) {
            if (map[i] > 1) return true;
        }
        return false;
    }
    if (count != 2) return false;
    if (A[res[0]] != B[res[1]] || A[res[1]] != B[res[0]]) return false;
    return true;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN 
 * @Date: 2020-03-26 21:15:56 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-03-26 21:40:52
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

digits = "234";
digitsArr = {"abc", "def", "ghi"};
ret = "bei"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool backTrack(char* digits, int sLen, int* ret, int num) {
    if (digits == NULL) {
        return true;
    }
    for (i in digits[num]) {
        ret[num] += b;
        if (isTrue(ret) == true) {
            digits2 = digits[i]->allchild;
            if (backTrack(digits2, sLen, ret, num + 1) == true) return true;
        }
    }
    return false；
}

char* letterCombinations(char* digits){
    int sLen = strlen(digits);
    char* ret = malloc(sizeof(char) * sLen);
    if (backTrack(digits, sLen, ret, 0)) return ret;
    else NULL;
}

int main() {
    
    return 0;
}
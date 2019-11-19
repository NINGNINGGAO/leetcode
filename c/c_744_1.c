/*
 * @Author: AGOGIN
 * @Date: 2019-11-19 19:44:25
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-19 19:49:52
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
char nextGreatestLetter(char* letters, int lettersSize, char target){
    int minValue = INT_MAX;
    char minLetters = 'z';
    int temp;
    for (int i = 0; i < lettersSize; i++) {
        temp = letters[i] - target;
        if (temp > 0 && temp < minValue) minValue = temp;
        if (letters[i] < minLetters) minLetters = letters[i];
    }
    if (minValue == INT_MAX) return minLetters;
    else return target + minValue;
}

int main() {

    return 0;
}
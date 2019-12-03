/*
 * @Author: AGOGIN
 * @Date: 2019-12-03 09:56:33
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-12-03 10:05:15
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int make(char c) {
    switch (c) {
        case ' ': return 0;
        case '+':
        case '-': return 1;
        case '.': return 3;
        case 'e': return 4;
        default:
            if (isdigit(c)) return 2;
    }
    return -1;
}
bool isNumber(char * s){
    int state = 0;
    int finals[] = {0,0,0,1,0,1,1,0,1};
    int transfer[][5] = {{ 0, 1, 6, 2,-1},{-1,-1, 6, 2,-1},{-1,-1, 3,-1,-1},\
    { 8,-1, 3,-1, 4},{-1, 7, 5,-1,-1},{ 8,-1, 5,-1,-1},\
    { 8,-1, 6, 3, 4},{-1,-1, 5,-1,-1},{ 8,-1,-1,-1,-1}};
    for (int i = 0; i < strlen(s); i++) {
        int temp = make(s[i]);
        if (temp < 0) return false;
        state = transfer[state][temp];
        if (state < 0) return false;
    }
    return finals[state];
}

int main() {

    return 0;
}
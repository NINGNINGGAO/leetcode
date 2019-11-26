/*
 * @Author: AGOGIN
 * @Date: 2019-11-26 16:32:45
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-26 16:37:30
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))
int maxNumberOfBalloons(char * text){
    int arr[26] = {0};
    for (int i = 0; i < strlen(text); i++) {
        arr[text[i] - 'a']++;
    }
    int res = arr['a' - 'a'];
    arr['l' - 'a'] /= 2;
    arr['o' - 'a'] /= 2;
    int flag[4] = {'b' - 'a', 'l' - 'a', 'o' - 'a', 'n' - 'a'};
    for (int i = 0; i < 4; i++) {
        res = Min(res, arr[flag[i]]);
    }
    return res;
}

int main() {

    return 0;
}
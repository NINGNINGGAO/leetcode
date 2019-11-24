/*
 * @Author: AGOGIN
 * @Date: 2019-11-24 22:22:47
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-11-24 22:22:47
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int game(int* guess, int guessSize, int* answer, int answerSize){
    int res = 0;
    for (int i = 0; i < guessSize; i++) {
        res += (guess[i] == answer[i]) ? 1 : 0;
    }
    return res;
}

int main() {

    return 0;
}
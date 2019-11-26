/*
 * @Author: AGOGIN
 * @Date: 2019-11-26 20:49:56
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-26 21:08:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool isRepeat(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 1) return false;
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int numsSize = 9;
    int* nums = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < boardSize; i++) {
        memset(nums, 0, sizeof(int) * numsSize);
        for (int j = 0; j < boardColSize[i]; j++) {
            if (isdigit(board[i][j])) nums[board[i][j] - '1']++;
        }
        if (isRepeat(nums, numsSize) == false) return false;
    }
    for (int i = 0; i < boardColSize[0]; i++) {
        memset(nums, 0, sizeof(int) * numsSize);
        for (int j = 0; j < boardSize; j++) {
            if (isdigit(board[j][i])) nums[board[j][i] - '1']++;
        }
        if (isRepeat(nums, numsSize) == false) return false;
    }
    for (int i = 0; i < numsSize; i++) {
        memset(nums, 0, sizeof(int) * numsSize);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (isdigit(board[3 * ((3 * i) / 9) + j][(i * 3) % 9 + k])) nums[board[3 * ((3 * i) / 9) + j][(i * 3) % 9 + k] - '1']++;
            }
        }
        if (isRepeat(nums, numsSize) == false) return false;
    }
    free(nums);
    return true;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-12-05 15:26:29
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-12-05 15:26:29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
bool backTrack(const char** board, int boardSize, const int* boardColSize, const char * word, \
int count, bool** flag, int row, int col, const int* dRow, const int* dCol) {
    if (count == strlen(word)) return true;
    else {
        if (flag[row][col] == false && board[row][col] == word[count]) {
            flag[row][col] = true;
            if (count + 1 == strlen(word)) return true;
            for (int i = 0; i < 4; i++) {
                if (row + dRow[i] < 0 || row + dRow[i] >= boardSize || col + dCol[i] < 0 || \
                col + dCol[i] >= boardColSize[0]) continue;
                else {
                    bool temp = backTrack(board, boardSize, boardColSize, word, count + 1, flag, \
                    row + dRow[i], col + dCol[i], dRow, dCol);
                    if (temp == true) return true;
                }
            }
            flag[row][col] = false;
        }
    }
    return false;
}
void freeFlag(int** flag, int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        free(flag[i]);
    }
    free(flag);
}
bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int sLen = strlen(word);
    int count = 0;
    int dRow[4] = {1,-1,0,0};
    int dCol[4] = {0,0,1,-1};
    bool** flag = malloc(sizeof(bool*) * boardSize);
    for (int i = 0; i < boardSize; i++) {
        flag[i] = malloc(sizeof(bool) * boardColSize[i]);
        memset(flag[i], 0, sizeof(bool) * boardColSize[i]);
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == word[0]) {
                bool temp = backTrack(board, boardSize, boardColSize, word, 0, flag, i, j, dRow, dCol);
                if (temp == true) {
                    freeFlag(flag, boardSize);
                    return true;
                }
            }
        }
    }
    freeFlag(flag, boardSize);
    return false;
}

int main() {

    return 0;
}
/*
 * @Author: AGOGIN
 * @Date: 2019-11-28 16:44:02
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-28 17:38:01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
struct Node {
    bool rows[9][10];
    bool cols[9][10];
    bool boxes[9][10];
};
bool backTrack(struct Node* flag, char** board, int boardSize, int* boardColSize, int row, int col) {
    if (col == 9) {
        col = 0;
        row++;
        if (row == 9) {
            return true;
        }
    }
    if (board[row][col] == '.') {
        for (int i = 1; i <= 9; i++) {
            bool mid = ((flag->rows)[row][i] == false) && ((flag->cols)[col][i] == false) && ((flag->boxes)[(row / 3) * 3 + col / 3][i] == false);
            if (mid == true) {
                board[row][col] = i + '0';
                (flag->rows)[row][i] = true;
                (flag->cols)[col][i] = true;
                (flag->boxes)[(row / 3) * 3 + col / 3][i] = true;
                if (backTrack(flag, board, boardSize, boardColSize, row, col + 1)) return true;
                else {
                    board[row][col] = '.';
                    (flag->rows)[row][i] = false;
                    (flag->cols)[col][i] = false;
                    (flag->boxes)[(row / 3) * 3 + col / 3][i] = false;
                }
            }
        }
    } else {
        return backTrack(flag, board, boardSize, boardColSize, row, col + 1);
    }
    return false;
}
void solveSudoku(char** board, int boardSize, int* boardColSize){
    struct Node* flag = malloc(sizeof(struct Node));
    memset(flag, 0, sizeof(struct Node));
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] != '.') {
                (flag->rows)[i][board[i][j] - '0'] = true;
                (flag->cols)[j][board[i][j] - '0'] = true;
                (flag->boxes)[(i / 3) * 3 + j / 3][board[i][j] - '0'] = true;
            }
        }
    }
    backTrack(flag, board, boardSize, boardColSize, 0, 0);
    free(flag);
}

int main() {
    char temp[9][10] = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    char** board = malloc(sizeof(char*) * 9);
    int boardSize = 9;
    int boardColSize[9] = {9,9,9,9,9,9,9,9,9};
    for (int i = 0; i < boardSize; i++) {
        board[i] = temp[i];
    }
    solveSudoku(board, boardSize, boardColSize);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
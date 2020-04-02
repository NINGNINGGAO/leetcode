/*
 * @Author: AGOGIN 
 * @Date: 2020-04-02 23:44:27 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-03 00:25:40
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[] = {0, 1, -1};
        int rows = board.size();
        int cols = board[0].size();
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int countNum = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = row + neighbors[i];
                            int c = col + neighbors[j];
                            if ((r >= 0 && r < rows) && (c >= 0 && c < cols) && (abs(board[r][c]) == 1)) {
                                countNum++;
                            }
                        }
                    }
                }
                if (board[row][col] == 1 && (countNum < 2 || countNum > 3)) board[row][col] = -1;
                if (board[row][col] == 0 && countNum == 3) board[row][col] = 2;
            }
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == -1) board[row][col] = 0;
                else if (board[row][col] == 2) board[row][col] = 1;
            }
        }
    }
};

int main() {
    Solution s;
    int count = 4;
    int a[] = {0,1,0,0,0,1,1,1,1,0,0,0};
    vector<vector<int>> board(count);
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++) {
            board[i].push_back(a[i * 3 + j]);
        }
    }
    s.gameOfLife(board);
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
 * @Author: AGOGIN 
 * @Date: 2020-04-07 15:04:23 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-07 15:17:19
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row / 2; i++) {
            for (int j = 0; j < col; j++) {
                swap(matrix[i][j], matrix[row - 1 - i][j]);
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
/*
 * @Author: AGOGIN 
 * @Date: 2020-04-20 17:28:53 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2020-04-20 23:11:26
 */
#include <vector>
using namespace std;

struct Point {
    int row;
    int col;
    Point() : row(0), col(0) {};
    Point(int n, int m) {
        row = n;
        col = m;
    };
};

class UnionFindSet {
private:
    struct Node {
        Point parent;
        int rank;
        Node() : parent(-1, -1), rank(0){};
    };
    vector<vector<Node>> arr;
    int count;

public:
    UnionFindSet(vector<vector<char>> &grid) : arr(vector<vector<Node>>(grid.size(), vector<Node>(grid[0].size()))), count(0) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    arr[i][j].parent.row = i;
                    arr[i][j].parent.col = j;
                    count++;
                }
            }
        }
    };
    Point find(Point x) {
        Point ret;
        if (arr[x.row][x.col].parent.row != x.row || arr[x.row][x.col].parent.col != x.col) {
            ret = find(Point(arr[x.row][x.col].parent.row, arr[x.row][x.col].parent.col));
            arr[x.row][x.col].parent.row = ret.row;
            arr[x.row][x.col].parent.col = ret.col;
            return ret;
        }
        else return x;
    }
    void toUnion(Point x, Point y) {
        Point fx = find(x);
        Point fy = find(y);
        if (fx.row == fy.row && fx.col == fy.col) return;
        if (arr[fx.row][fx.col].rank > arr[fy.row][fy.col].rank) {
            arr[fy.row][fy.col].parent = fx;
        } else {
            arr[fx.row][fx.col].parent = fy;
            if (arr[fx.row][fx.col].rank == arr[fy.row][fy.col].rank) {
                arr[fy.row][fy.col].rank++;
            }
        }
        count--;
    }
    int getCount() {
        return count;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int row = grid.size();
        if (!row) return 0;
        int col = grid[0].size();
        UnionFindSet s(grid);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    if (i < row - 1 && grid[i + 1][j] == '1') {
                        s.toUnion(Point(i, j), Point(i + 1, j));
                    }
                    if (j < col - 1 && grid[i][j + 1] == '1') {
                        s.toUnion(Point(i, j), Point(i, j + 1));
                    }
                }
            }
        }
        return s.getCount();
    }
};
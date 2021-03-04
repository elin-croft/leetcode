/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#include<iostream>
#include<vector>
using std::vector;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m > 0){
            int n = matrix[0].size();
            _sums.resize(m + 1, vector<int>(n + 1));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    _sums[i + 1][j + 1] = _sums[i + 1][j] + _sums[i][j + 1] - _sums[i][j] + matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return _sums[row2 + 1][col2 + 1] - _sums[row1][col2 + 1] - _sums[row2 + 1][col1] + _sums[row1][col1];
    }
private:
    vector<vector<int>>_sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end


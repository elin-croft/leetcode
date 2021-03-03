/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        _sums.resize(n + 1);
        for(int i = 0; i < n; i++){
            _sums[i + 1] = _sums[i] + nums[i];
        }

    }
    
    int sumRange(int i, int j) {
        return _sums[j + 1] - _sums[i];
    }
private:
    vector<int>_sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end


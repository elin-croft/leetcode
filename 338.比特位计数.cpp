/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res(num + 1);
        int highBit = 0;
        for(int i = 1; i <= num; i++){
            if((i & (i - 1)) == 0){
                highBit = i;
            }
                res[i] = res[i - highBit] + 1;
        }
        return res;
    }
};
// @lc code=end


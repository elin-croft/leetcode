/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */
// @lc code=start
#include<iostream>
#include<vector>
#include<queue>
using std::vector;
using std::cin;
using std::cout;
using std::priority_queue;
using std::greater;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums):_k(k) {
        for(int i = 0; i < nums.size(); i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        _dataStream.push(val);
        if(_dataStream.size() > _k)
            _dataStream.pop();
        return _dataStream.top();
    }
private:
    int _k;
    priority_queue<int, vector<int>, greater<int> >_dataStream;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end


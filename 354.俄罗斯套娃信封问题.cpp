/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())
            return 0;
        // method one
        // int n = envelopes.size();
        // std::sort(envelopes.begin(), envelopes.end(), [&](const auto x, const auto y){
        //     return x[0] < y[0] ||(x[0] == y[0] && x[1] > y[1]);
        // });
        // vector<int>dp(n, 1);
        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(envelopes[i][1] > envelopes[j][1])
        //             dp[i] = std::max(dp[i], dp[j] + 1);
        //     }
        // }
        // return *std::max_element(dp.begin(), dp.end());
        // my method 
        int n = envelopes.size();
        vector<pair<int, int>>pEnvelopes(n);
        set<int>nums;
        for(int i = 0; i < envelopes.size(); i++){
            nums.insert(envelopes[i][0]);
            pEnvelopes[i].first = envelopes[i][0];
            pEnvelopes[i].second = envelopes[i][1];
        }
        sort(pEnvelopes.begin(), pEnvelopes.end());
        int base = pEnvelopes[0].first;
        vector<vector<pair<int, int>>>dp(nums.size());
        int i = 0, j = 0;
        while(i < n){
            if(pEnvelopes[i].first == base){
                dp[j].emplace_back(1, pEnvelopes[i].second);
                i++;
            }
            else{
                sort(dp[j].begin(), dp[j].end(), [&](pair<int, int>x, pair<int, int>y){
                    return x.first > y.first;
                });
                j++;
                base = pEnvelopes[i].first;
                while(i < n && pEnvelopes[i].first == base){
                    int cnt = 0;
                    for(int m = 0; m < j; m++){
                        for(auto& [count, h]:dp[m]){
                            if(h < pEnvelopes[i].second){
                                cnt = max(cnt, count);
                                break;
                            }
                        }
                    }
                    dp[j].emplace_back(cnt + 1, pEnvelopes[i].second);
                    i++;
                }
            }
        }
        int maxNum = 0;
        for(auto& item:dp){
            for(auto& [count, h]:item){
                maxNum = max(count, maxNum);
            }
        }
        return maxNum;
    }
};
// @lc code=end


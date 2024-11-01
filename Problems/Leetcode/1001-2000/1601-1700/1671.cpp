#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), ans = 0, suf;
        vector<int> g, dp(n);

        for (int i = 0; i < n; ++i) {
            auto iter = ranges::lower_bound(g, nums[i]);
            dp[i] = iter - g.begin() + 1;
            if (iter == g.end()) {
                g.emplace_back(nums[i]);
            } else {
                *iter = nums[i];
            }
        }

        g.clear();
        for (int i = n - 1; i >= 0; --i) {
            auto iter = ranges::lower_bound(g, nums[i]);
            suf = iter - g.begin() + 1;
            if (iter == g.end()) {
                g.emplace_back(nums[i]);
            } else {
                *iter = nums[i];
            }

            if (dp[i] > 1 && suf > 1) {
                ans = max(ans, dp[i] + suf);
            }
        }

        return n - ans + 1; // 重复算了一次
    }
};
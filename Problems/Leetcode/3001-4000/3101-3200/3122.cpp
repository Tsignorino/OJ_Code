#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(10);
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(10);
            for (int j = 0; j < m; ++j) {
                cnt[grid[j][i]]++;
            }

            vector<int> new_dp(10, INT_MAX);
            for (int p = 0; p < 10; ++p) {
                for (int q = 0; q < 10; ++q) {
                    if (p == q) {
                        continue;
                    }
                    new_dp[p] = min(new_dp[p], dp[q] + (m - cnt[p]));
                }
            }

            dp = std::move(new_dp);
        }
        return ranges::min(dp);
    }
};
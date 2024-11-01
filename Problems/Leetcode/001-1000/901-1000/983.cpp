#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
    vector<int> durations {1, 7, 30};

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 0, j = i; k < 3; ++k) {
                while (j < n && days[i] + durations[k] > days[j]) {
                    j++;
                }
                dp[i] = min(dp[i], costs[k] + dp[j]);
            }
        }

        return dp[0];

        // vector<int> memo(n + 1, INT_MAX);
        // function<int(int)> dfs = [&](int i) -> int {
        //     if (i == n) {
        //         return 0;
        //     }

        //     int& res = memo[i];
        //     if (res != INT_MAX) {
        //         return res;
        //     }

        //     for (int k = 0, j = i; k < 3; ++k) {
        //         while (j < n && days[i] + durations[k] > days[j]) {
        //             j++;
        //         }
        //         res = min(res, costs[k] + dfs(j));
        //     }
        //     return res;
        // };

        // return dfs(0);
    }
};

int main() {
    Solution sol;

    return 0;
}
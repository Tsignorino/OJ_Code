#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector f(maxTime + 1, vector<int>(n, INT_MAX / 2));
        f[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; ++t) {
            for (auto& e : edges) {
                int i = e[0], j = e[1], w = e[2];
                if (w <= t) {
                    f[t][i] = min(f[t][i], f[t - w][j] + passingFees[i]);
                    f[t][j] = min(f[t][j], f[t - w][i] + passingFees[j]);
                }
            }
        }

        int ans = INT_MAX / 2;
        for (int t = 1; t <= maxTime; ++t) {
            ans = min(ans, f[t][n - 1]);
        }
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
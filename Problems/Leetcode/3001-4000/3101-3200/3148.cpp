#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MIN;
        vector<int> g(n + 1, INT_MAX);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int minV = min(g[j + 1], g[j]);
                g[j + 1] = min(grid[i][j], minV);
                ans = max(ans, grid[i][j] - minV);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}
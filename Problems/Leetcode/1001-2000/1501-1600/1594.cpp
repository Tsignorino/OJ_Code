#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> maxV(m, vector<long long>(n));
        vector<vector<long long>> minV(m, vector<long long>(n));
        maxV[0][0] = minV[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            maxV[i][0] = minV[i][0] = maxV[i - 1][0] * grid[i][0];
        }
        for (int i = 1; i < n; ++i) {
            maxV[0][i] = minV[0][i] = maxV[0][i - 1] * grid[0][i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] >= 0) {
                    maxV[i][j] = max(maxV[i][j - 1], maxV[i - 1][j]) * grid[i][j];
                    minV[i][j] = min(minV[i][j - 1], minV[i - 1][j]) * grid[i][j];
                } else {
                    maxV[i][j] = min(minV[i][j - 1], minV[i - 1][j]) * grid[i][j];
                    minV[i][j] = max(maxV[i][j - 1], maxV[i - 1][j]) * grid[i][j];
                }
            }
        }
        return maxV[m - 1][n - 1] < 0 ? -1 : maxV[m - 1][n - 1] % MOD;
    }
};

int main() {
    Solution sol;

    return 0;
}
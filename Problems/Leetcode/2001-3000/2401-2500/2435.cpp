#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        // 改用普通数组，后移减少判断，效率改善明显
        vector f(n, vector(m, vector<int>(k)));
        f[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int p = 0; p < k; ++p) {
                    if (i > 0) {
                        f[i][j][(p + grid[i][j]) % k] += f[i - 1][j][p];
                        f[i][j][(p + grid[i][j]) % k] %= MOD;
                    }
                    if (j > 0) {
                        f[i][j][(p + grid[i][j]) % k] += f[i][j - 1][p];
                        f[i][j][(p + grid[i][j]) % k] %= MOD;
                    }
                }
            }
        }
        return f[n - 1][m - 1][0];
    }
};

int main() {
    Solution sol;

    return 0;
}
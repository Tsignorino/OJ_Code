#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, INT_MAX));
        function<int(int, int)> dfs = [&](int r, int c) -> int {
            if (r == n - 1) {
                return grid[r][c];
            }

            int& res = memo[r][c];
            if (res != INT_MAX) {
                return res;
            }

            for (int i = 0; i < m; ++i) {
                res = min(res, moveCost[grid[r][c]][i] + dfs(r + 1, i));
            }
            res += grid[r][c];
            return res;
        };

        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, dfs(0, i));
        }
        return ans;
    }

    int minPathCost_(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
        f[n - 1] = grid[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    f[i][j] = min(f[i][j], f[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                f[i][j] += grid[i][j];
            }
        }
        return ranges::min(f[0]);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid {
        {5, 3},
        {4, 0},
        {2, 1}
    };
    vector<vector<int>> moveCost {
        {9,  8 },
        {1,  5 },
        {10, 12},
        {18, 6 },
        {2,  4 },
        {14, 3 }
    };
    sol.minPathCost(grid, moveCost);

    return 0;
}
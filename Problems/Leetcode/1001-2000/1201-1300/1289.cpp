#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, INT_MAX / 2));
        function<int(int, int)> dfs = [&](int r, int c) -> int {
            if (r == n - 1) {
                return grid[r][c];
            }
            if (c < 0 || c >= n) {
                return INT_MAX / 2;
            }

            int& res = memo[r][c];
            if (res != INT_MAX / 2) {
                return res;
            }

            for (int i = 0; i < n; ++i) {
                if (i == c) {
                    continue;
                }
                res = min(res, dfs(r + 1, i));
            }
            res += grid[r][c];
            return res;
        };

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, dfs(0, i));
        }
        return ans;
    }

public:
    int minFallingPathSum_(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MAX / 2));
        for (int i = 0; i < n; ++i) {
            f[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (j == k) {
                        continue;
                    }
                    f[i][j] = min(f[i][j], f[i - 1][k] + grid[i][j]);
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, f[n - 1][i]);
        }
        return ans;
    }

public:
    int minFallingPathSum__(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            int id1 = -1, id2 = -1;
            for (int j = 0; j < n; ++j) {
                dp[j] += grid[i][j];
                if (id1 == -1 || dp[j] < dp[id1]) {
                    id2 = id1;
                    id1 = j;
                } else if (id2 == -1 || dp[j] < dp[id2]) {
                    id2 = j;
                }
            }

            if (i == n - 1) {
                break;
            }
            for (int j = 0, m1 = dp[id1], m2 = dp[id2]; j < n; ++j) {
                dp[j] = id1 != j ? m1 : m2;
            }
        }

        return ranges::min(dp);
    }

public:
    int minFallingPathSum___(vector<vector<int>>& grid) {
        int n = grid.size();
        int fi = 0, se = 0, fi_idx = -1;
        for (int i = 0; i < n; ++i) {
            int cur_fi = INT_MAX, cur_se = INT_MAX, cur_fi_idx = -1;
            for (int j = 0; j < n; ++j) {
                int cur = (j != fi_idx ? fi : se) + grid[i][j];
                if (cur < cur_fi) {
                    cur_se = cur_fi;
                    cur_fi = cur;
                    cur_fi_idx = j;
                } else if (cur < cur_se) {
                    cur_se = cur;
                }
            }

            fi = cur_fi;
            se = cur_se;
            fi_idx = cur_fi_idx;
        }

        return fi;
    }
};

int main() {
    Solution sol;

    return 0;
}